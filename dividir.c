#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *current = l->prox;  // Inicia na primeira célula, ignorando o nó cabeça
    celula *current_l1 = l1;    // Mantém o ponteiro no último nó de l1
    celula *current_l2 = l2;    // Mantém o ponteiro no último nó de l2

    // Inicializa ambas as listas
    l1->prox = NULL;
    l2->prox = NULL;

    // Enquanto a lista não estiver vazia
    while (current != NULL) {
        celula *temp = current->prox;  // Salva o próximo nó antes de modificá-lo
        if (current->dado % 2 == 0) {  // Se o número for par
            current_l2->prox = current; // Modifica o ponteiro para apontar para o novo nó
            current_l2 = current;       // Adiciona o nó à lista l2
            current->prox = NULL;       // O último nó de l2 aponta para NULL
        } else {  // Se o número for ímpar
            current_l1->prox = current; // Modifica o ponteiro para apontar para o novo nó
            current_l1 = current;       // Adiciona o nó à lista l1
            current->prox = NULL;       // O último nó de l1 aponta para NULL
        }
        current = temp;  // Avança para o próximo nó
    }
}
