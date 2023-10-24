#include <stdio.h>


typedef struct fila {
int *dados;
int N, p, u;
} fila;


int enfileira(fila *f, int x){

    if(f->u - f->p >= f->N) return 0;

    f->dados[f->u] = x;

    f->u++;

    return 1;


}