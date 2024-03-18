#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Adicionado para sysconf()

#define N 100 // Tamanho da matriz e do vetor

int matriz[N][N];
int vetor[N];
int resultado[N];

// Estrutura para passar argumentos para a thread
typedef struct {
    int inicio;
    int fim;
} thread_arg;

// Função que cada thread executa
void *multiplica_linhas(void *arg) {
    thread_arg *t_arg = (thread_arg *)arg;
    int inicio = t_arg->inicio;
    int fim = t_arg->fim;

    for (int i = inicio; i < fim; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Preenche a matriz com números
    int contador = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = contador++;
        }
    }

    // Preenche o vetor com números 
    for (int i = 0; i < N; i++) {
        vetor[i] = contador++;
    }

    // Imprime a matriz
    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprime o vetor
    printf("\nVetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", vetor[i]);
    }

    // Obtém o número de núcleos do processador
    int num_nucleos = sysconf(_SC_NPROCESSORS_ONLN);

    // Calcula quantas linhas cada thread irá processar
    int linhas_por_thread = N / num_nucleos;

    // Inicializa as threads
    pthread_t threads[num_nucleos];
    for (int i = 0; i < num_nucleos; i++) {
        thread_arg *t_arg = (thread_arg *)malloc(sizeof(thread_arg));
        t_arg->inicio = i * linhas_por_thread;
        t_arg->fim = (i == num_nucleos - 1) ? N : (i + 1) * linhas_por_thread;
        pthread_create(&threads[i], NULL, multiplica_linhas, (void *)t_arg);
    }

    // Aguarda as threads terminarem
    for (int i = 0; i < num_nucleos; i++) {
        pthread_join(threads[i], NULL);
    }

    // Imprime o resultado
    printf("\nResultado da multiplicação:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultado[i]);
    }

    return 0;
}