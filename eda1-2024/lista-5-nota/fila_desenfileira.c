#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados; // Vetor que armazena os elementos da fila
    int N; // Capacidade máxima da fila
    int p, u; // Índices de início (p) e fim (u) da fila
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) { // Verifica se a fila está vazia
        return 0; // Retorna 0 se a fila estiver vazia
    }
    *y = f->dados[f->p]; // Salva o elemento removido em y
    f->p = (f->p + 1) % f->N; // Atualiza o índice de início da fila (fila circular)
    return 1; // Retorna 1 indicando sucesso na remoção
}
