#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = x;
    
    if (*f == NULL) {
        nova_celula->prox = nova_celula; // Aponta para si mesma
        *f = nova_celula; // Nova célula torna-se a cabeça da fila
    } else {
        nova_celula->prox = (*f)->prox; // Nova célula aponta para o próximo da cabeça
        (*f)->prox = nova_celula; // Cabeça aponta para a nova célula
        *f = nova_celula; // Nova célula torna-se a nova cabeça
    }
}

int desenfileira(celula *f, int *y) {
    if (f == NULL || f->prox == f) // Verifica se a fila está vazia
        return 0; // Fila vazia, não há o que desenfileirar
    
    celula *temp = f->prox; // Nó a ser desenfileirado
    *y = temp->dado; // Guarda o valor a ser desenfileirado
    
    if (f->prox == f) { // Verifica se é o último nó
        free(f); // Libera a cabeça da fila
        f = NULL;
    } else {
        f->prox = temp->prox; // Atualiza o próximo da cabeça da fila
        free(temp); // Libera o nó desenfileirado
    }
    
    return 1; // Desenfileiramento bem-sucedido
}
