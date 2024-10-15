#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que contém os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

void empilha(pilha *p, int x) {
    if (p->topo == p->N) { // Verifica se a pilha está cheia
        // Dobrar o tamanho do vetor
        p->N *= 2;
        p->v = (int *)realloc(p->v, p->N * sizeof(int));
        if (p->v == NULL) {
            printf("Erro: Não foi possível alocar memória.\n");
            exit(EXIT_FAILURE);
        }
    }
    p->v[p->topo++] = x; // Insere o elemento x no topo da pilha e incrementa o topo
}

int desempilha(pilha *p, int *y) {
    if (p->topo == 0) { // Verifica se a pilha está vazia
        return 0; // Retorna 0 se a pilha estiver vazia
    }
    *y = p->v[--(p->topo)]; // Salva o elemento desempilhado em y e decrementa o topo
    return 1; // Retorna 1 indicando sucesso no desempilhamento
}
