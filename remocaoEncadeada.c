#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    if (f->prox == NULL) {
        // A fila está vazia, não é possível remover elementos.
        return 0;
    }

    celula *temp = f->prox; // Guarda uma referência ao primeiro elemento da fila.

    *y = temp->dado; // Copia o valor do primeiro elemento para *y.

    f->prox = temp->prox; // Atualiza o ponteiro para o próximo elemento na fila.

    free(temp); // Libera a memória do elemento removido.

    return 1; // Remoção bem-sucedida.
}



typedef struct celula{
    int dado;
    struct celula *prox;
}celula;


desenfileira(int *f, int *y){
    if(f->prox == NULL) return 0;

    celula *temp = f->prox;

    *y = temp->dado;

    f->prox = temp->prox;

    free(temp);


    

    return 1;


}