#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    if ((f->u + 1) % f->N == f->p) {
        // A fila está cheia, redimensione o vetor
        int novoTamanho = f->N * 2;
        int *novoDados = (int *)malloc(sizeof(int) * novoTamanho);
        if (novoDados == NULL) {
            return 0; // Falha na alocação de memória
        }

        int j = 0;
        for (int i = f->p; i != f->u; i = (i + 1) % f->N) {
            novoDados[j] = f->dados[i];
            j++;
        }

        novoDados[j] = x;
        f->p = 0;
        f->u = j + 1;
        f->N = novoTamanho;
        free(f->dados);
        f->dados = novoDados;
    } else {
        f->dados[f->u] = x;
        f->u = (f->u + 1) % f->N;
    }
    return 1; // Inserção bem-sucedida
}
