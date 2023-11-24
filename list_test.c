#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} nodo_t;

// Função para inserir ordenadamente na lista
void insereOrdenado(int valor, nodo_t **cabeca) {
    nodo_t *novoNodo;

    if (!(novoNodo = (nodo_t*) malloc(sizeof(nodo_t)))) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNodo -> valor = valor;
    novoNodo -> proximo = NULL;

    // Caso a lista esteja vazia ou o novo valor seja menor que o primeiro valor
    if ((!(*cabeca)) || (valor < (*cabeca) -> valor)) {
        novoNodo -> proximo = *cabeca;
        *cabeca = novoNodo;
        return;
    }

    // Encontrar a posição correta na lista
    nodo_t *atual = *cabeca;
    while (atual -> proximo != NULL && atual -> proximo -> valor < valor) {
        atual = atual -> proximo;
    }

    // Inserir o novo nó na posição correta
    novoNodo -> proximo = atual -> proximo;
    atual -> proximo = novoNodo;
}

void removeElemento(int valor, nodo_t **cabeca) {
    nodo_t *atual = *cabeca;
    nodo_t *anterior = NULL;

    // Procurar o valor na lista
    while ((atual) && (atual -> valor != valor)) {
        anterior = atual;
        atual = atual -> proximo;
    }

    // Se o valor não foi encontrado, não há nada para remover
    if (atual == NULL) {
        return;
    }

    // Remover o nodo da lista
    if (anterior == NULL) 
        *cabeca = atual -> proximo;
    else 
        anterior -> proximo = atual -> proximo;

    // Liberar a memória alocada para o nodo removido
    free(atual);
}

// Função para liberar a memória alocada para a lista
void liberaLista(nodo_t *cabeca) {
    nodo_t *atual = cabeca;

    while (atual != NULL) {
        nodo_t *proximo = atual -> proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    nodo_t *cabeca = NULL;
    int valor;
    char mode;

    while (scanf("%c %d", &mode, &valor)) {
        printf("%d\n", valor);
        if (mode == 'i')
            insereOrdenado(valor, &cabeca);
        if (mode == 'r')
            removeElemento(valor, &cabeca);
    }

    // Liberar a memória alocada para a lista
    liberaLista(cabeca);

    return 0;
}