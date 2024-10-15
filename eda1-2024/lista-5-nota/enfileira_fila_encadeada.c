#include <stdlib.h>

// Declaração da estrutura da célula da lista encadeada
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para enfileirar um elemento na fila encabeçada por f
celula *enfileira(celula *f, int x) {
    // Criar uma nova célula para o novo elemento
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->prox = f->prox;
   f->prox = nova;
   f->dado = x;
   return nova;
}
