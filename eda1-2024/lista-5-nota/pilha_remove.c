#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) { // Verifica se a pilha está vazia
        return 0; // Retorna 0 se a pilha estiver vazia
    }
    celula *temp = p->prox; // Salva o endereço do topo da pilha
    *y = temp->dado; // Salva o elemento removido em y
    p->prox = temp->prox; // Atualiza o ponteiro do topo da pilha
    free(temp); // Libera a célula removida da memória
    return 1; // Retorna 1 indicando sucesso na remoção
}
