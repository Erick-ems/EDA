#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    if (f->u == f->N) {
        // A fila está cheia, redimensione o vetor
        int novoTamanho = (f->N == 0) ? 1 : f->N * 2; // Inicializa com tamanho 1 se for vazio
        int *novoDados = (int *)malloc(sizeof(int) * novoTamanho);
        if (novoDados == NULL) {
            return 0; // Falha na alocação de memória
        }

        for (int i = 0; i < f->N; i++) {
            novoDados[i] = f->dados[i];
        }

        free(f->dados);
        f->dados = novoDados;
        f->N = novoTamanho;
    }

    f->dados[f->u] = x;
    f->u++;
    return 1; // Inserção bem-sucedida
}