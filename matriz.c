#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher uma matriz com números aleatórios
void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 100; // Gera números aleatórios de 0 a 99
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}


// Função para somar duas matrizes
void somarMatrizes(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Função para calcular a matriz transposta
void calcularTransposta(int **matriz, int **transposta, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}


int main() {
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Define o tamanho das matrizes
    int linhas = 3000;
    int colunas = 3000;

    // Cria duas matrizes
    int matriz1[linhas][colunas];
    int matriz2[linhas][colunas];

    // Preenche as matrizes com números aleatórios
    preencherMatriz(matriz1, linhas, colunas);
    preencherMatriz(matriz2, linhas, colunas);

    // Imprime as matrizes
    printf("Matriz 1:\n");
    imprimirMatriz(matriz1, linhas, colunas);

    printf("\nMatriz 2:\n");
    imprimirMatriz(matriz2, linhas, colunas);

    // Cria uma matriz para armazenar a soma
    int resultado[linhas][colunas];

    // Chama a função para somar as matrizes
    somarMatrizes(matriz1, matriz2, resultado, linhas, colunas);
    imprimirMatriz(resultado, linhas, colunas);

    // Cria uma matriz para armazenar a transposta
    int transposta[linhas][colunas];

    // Chama a função para calcular a matriz transposta
    calcularTransposta(matriz1, transposta, linhas, colunas);
    imprimirMatriz(transposta, linhas, colunas);





    return 0;
}
