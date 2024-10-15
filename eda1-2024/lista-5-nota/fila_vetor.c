#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que representa a fila
    int N; // Tamanho da fila
    int inicio, fim; // Indicadores de inicio e final da fila
} fila;

int enfileira(fila *f, int x) {
    if ((f->fim + 1) % f->N == f->inicio) { // Verifica se a fila está cheia
        return 0; // Retorna 0 se a fila estiver cheia
    }
    f->v[f->fim] = x; // Insere o elemento x na posição do fim da fila
    f->fim = (f->fim + 1) % f->N; // Atualiza o indicador de fim
    return 1; // Retorna 1 indicando sucesso no enfileiramento
}

int desenfileira(fila *f, int *y) {
    if (f->inicio == f->fim) { // Verifica se a fila está vazia
        return 0; // Retorna 0 se a fila estiver vazia
    }
    *y = f->v[f->inicio]; // Salva o elemento desenfileirado em y
    f->inicio = (f->inicio + 1) % f->N; // Atualiza o indicador de inicio
    return 1; // Retorna 1 indicando sucesso no desenfileiramento
}
