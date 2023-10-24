// desenfileirar uma circular

#include <stdio.h> // Inclui a biblioteca padrão para entrada/saída, necessária para usar funções como printf.
#include <stdlib.h> // Inclui a biblioteca padrão para alocação dinâmica de memória, necessária para usar a função malloc.

typedef struct fila { // Define uma estrutura chamada 'fila' para representar a fila.
    int *dados; // Declara um ponteiro para inteiros chamado 'dados', que será usado para armazenar os elementos da fila.
    int N, p, u; // Declara três variáveis inteiras: 'N' (tamanho da fila), 'p' (início da fila) e 'u' (final da fila).
} fila; // Define um tipo de dado 'fila' usando typedef.

int desenfileira(fila *f, int *y) { // Declara uma função chamada 'desenfileira' que recebe um ponteiro para 'fila' e um ponteiro para inteiro como argumentos.
    if (f->p == f->u) { // Verifica se o início da fila 'p' é igual ao final da fila 'u'.
        // A fila está vazia, não é possível desenfileirar
        return 0; // Retorna 0 para indicar que a operação de desenfileirar não foi bem-sucedida (fila vazia).
    }

    *y = f->dados[f->p]; // Armazena o valor apontado por 'p' (início da fila) na variável apontada por 'y'.
    f->p = (f->p + 1) % f->N; // Atualiza o início da fila 'p' para apontar para o próximo elemento da fila, usando uma operação de módulo '%'.

    return 1; // Retorna 1 para indicar que a operação de desenfileirar foi bem-sucedida.
}

#include <stdio.h>


typedef struct fila{
    int *dado;
    int N, p, u;
}fila;


desenfileira(int *f, int *y){
    if(f->p == f->u) return 0;

    *y = f->dados[f->p];
    f->p = (f->p + 1) % f-> N;
}