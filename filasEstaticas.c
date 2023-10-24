#include <stdio.h>
#include <stdlib.h>


typedef struct fila {
int *v; // Vetor que representa a fila
int N; // Tamanho da fila
int inicio, fim; // Indicadores de inicio e final da fila
} fila;


int enfileira (fila *f, int x){


    




}

int desenfileira (fila *f, int *y){
     
    if(f->inicio == f->fim) return 0;


    *y = f->v[f->p];
    f->p++;

    return 1;

}
