#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){// passamos as celulas e o ponteiro que queremos salvar o valor

  if(f->prox == NULL) return 0; // verifica se a lista está vazia

  celula *temp = f->prox; //criamos uma celula temporaria para armazazenar o dado do primeiro elemento da lista depois da cabeça
  *y = temp->dado; // salvamos esse valor em y
  f->prox = temp->prox; // refazemos a referencia dos ponteiros para a remoção do primeiro elemento
  free(temp); // liberamos o celula temporaria
  return 1;

}