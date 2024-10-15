#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados; // Vetor que armazena os elementos da pilha
    int N; // Capacidade máxima da pilha
    int topo; // Índice que indica a primeira posição livre da pilha
} pilha;

int desempilha(pilha *p, int *y) {
    if (p->topo == 0) { // Verifica se a pilha está vazia
        return 0; // Retorna 0 se a pilha estiver vazia
    }
    *y = p->dados[--(p->topo)]; // Salva o elemento removido em y e decrementa o topo
    return 1; // Retorna 1 indicando sucesso na remoção
}
