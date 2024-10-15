#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    nova_celula->dado = x;
    if (*f == NULL) {
        nova_celula->prox = nova_celula;
        *f = nova_celula;
    } else {
        nova_celula->prox = (*f)->prox;
        (*f)->prox = nova_celula;
        *f = nova_celula;
    }
}

int desenfileira(celula **f, int *y) {
    if (*f == NULL) {
        return 0;
    }
    celula *temp = (*f)->prox;
    *y = temp->dado;
    if (*f == (*f)->prox) {
        free(*f);
        *f = NULL;
    } else {
        (*f)->prox = temp->prox;
        free(temp);
    }
    return 1;
}
