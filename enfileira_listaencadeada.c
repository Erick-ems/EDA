#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para enfileirar (inserir no final da fila)
celula *enfileira(celula *f, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        return NULL; // Falha na alocação de memória
    }
    novo->dado = x;
    novo->prox = NULL;

    if (f == NULL) {
        // A fila está vazia, o novo elemento será o único na fila
        return novo;
    } else {
        celula *atual = f;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
        return f;
    }
}