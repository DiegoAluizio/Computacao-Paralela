#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3 // Tamanho da matriz e do vetor

int matriz[N][N];
int vetor[N];
int resultado[N];
pthread_t threads[N];

// Estrutura para passar argumentos para a thread
typedef struct {
    int linha;
} thread_arg;

// Função que cada thread executa
void *multiplica_linha(void *arg) {
    thread_arg *t_arg = (thread_arg *)arg;
    int linha = t_arg->linha;

    for (int i = 0; i < N; i++) {
        resultado[linha] += matriz[linha][i] * vetor[i];
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

    // Inicializa as threads
    for (int i = 0; i < N; i++) {
        thread_arg *t_arg = (thread_arg *)malloc(sizeof(thread_arg));
        t_arg->linha = i;
        pthread_create(&threads[i], NULL, multiplica_linha, (void *)t_arg);
    }

    // Aguarda as threads terminarem
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Imprime o resultado
    printf("\nResultado da multiplicação:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultado[i]);
    }

    return 0;
}
