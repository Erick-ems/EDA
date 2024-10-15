#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados; // Vetor que armazena os elementos da pilha
    int N; // Capacidade máxima da pilha
    int topo; // Índice que indica a primeira posição livre da pilha
} pilha;

int empilha(pilha *p, int x) {
    if (p->topo == p->N) { // Verifica se a pilha está cheia
        // Redimensiona o vetor dados
        int *novo_dados = (int *)realloc(p->dados, 2 * p->N * sizeof(int));
        if (novo_dados == NULL) {
            printf("Erro: Não foi possível alocar memória.\n");
            return 0; // Retorna 0 indicando falha na inserção
        }
        p->dados = novo_dados;
        p->N *= 2;
    }
    p->dados[p->topo++] = x; // Insere o elemento x na posição topo e incrementa o topo
    return 1; // Retorna 1 indicando sucesso na inserção
}
