#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{
    if (l == NULL) return;

    if (l->dado % 2 == 0) // Se o número é par
    {
        l1->prox = l;      // Adiciona l ao fim de l1
        l1 = l1->prox;    // Atualiza o ponteiro l1
    }
    else // Se o número é ímpar
    {
        l2->prox = l;     // Adiciona l ao fim de l2
        l2 = l2->prox;    // Atualiza o ponteiro l2
    }

    divide_lista(l->prox, l1, l2); // Chama a função recursivamente para o próximo nó
    l->prox = NULL;                // Desconecta o nó atual da lista original
}