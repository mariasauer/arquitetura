#include <stdio.h>
#include <stdlib.h>

void insere_Ordenado(int valor, int **vetor, int *tamanho) {
    int i, j;

    // Encontrar a posição correta para inserir o valor no vetor ordenado
    for (i = 0; i < *tamanho && valor > (*vetor)[i]; i++) {
    }

    // Realocar o vetor se necessário
    *tamanho += 1;
    *vetor = (int *)realloc(*vetor, *tamanho * sizeof(int));

    for (j = *tamanho - 1; j > i; j--) 
        (*vetor)[j] = (*vetor)[j - 1];

    (*vetor)[i] = valor;
}

void remove_Elemento(int valor, int **vetor, int *tamanho) {
    int i, j;

    // Encontrar a posição do valor no vetor
    for (i = 0; i < *tamanho && valor != (*vetor)[i]; i++) {
    }

    if (i == *tamanho) 
        return;
    
    for (j = i; j < *tamanho - 1; j++) {
        (*vetor)[j] = (*vetor)[j + 1];
    }

    *tamanho -= 1;
    *vetor = (int *)realloc(*vetor, *tamanho * sizeof(int));
}

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int valor;
    char mode;

    while (scanf("%c %d", &mode, &valor) != -1) {
        if (mode == 'i')
            insere_Ordenado(valor, &vetor, &tamanho);
        if (mode == 'r')
            remove_Elemento(valor, &vetor, &tamanho);
    }

    free(vetor);
    return 0;
}
