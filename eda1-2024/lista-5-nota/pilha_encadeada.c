#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    nova_celula->dado = x;
    nova_celula->prox = p->prox; // A nova célula aponta para o antigo topo da pilha
    p->prox = nova_celula; // Atualiza o topo da pilha para a nova célula
}

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) { // Verifica se a pilha está vazia
        return 0; // Retorna 0 se a pilha estiver vazia
    }
    celula *temp = p->prox; // Salva o endereço do topo da pilha
    *y = temp->dado; // Salva o elemento desempilhado em y
    p->prox = temp->prox; // Atualiza o topo da pilha
    free(temp); // Libera a célula removida da memória
    return 1; // Retorna 1 indicando sucesso no desempilhamento
}
