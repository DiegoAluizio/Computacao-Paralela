#include <stdio.h>
#include <stdlib.h>

#define N 100 // Tamanho da matriz e do vetor

int matriz[N][N];
int vetor[N];
int resultado[N];

// Função para multiplicar a matriz pelo vetor
void multiplicarMatrizVetor() {
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
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

    // Multiplica a matriz pelo vetor
    multiplicarMatrizVetor();

    // Imprime o resultado
    printf("\nResultado da multiplicação:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultado[i]);
    }

    return 0;
}