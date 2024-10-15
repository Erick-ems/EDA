#include <stdio.h>
#include <stdlib.h>

// Declração da estrutura do tipo fila
typedef struct fila
{
  int *dados;
  int N, p, u;
}fila;

//Função que vai redimendionar a nossa fila estatica
void redimensionaFila(fila *f){
  int novoTamanho = f->N * 2; // criamos uma variavel para receber o novo tamanho com o dobro da anterior
  int *novosDados = (int *)malloc(novoTamanho * sizeof(int)); // criamos uma nova lista com o novo tamanho
  int i, j; // inicializamos duas variaveis


  for(i = 0, j = f->p; j != f->u; i++, j++){ // o loop for vai percorrer a lista original e copiar para a nova lista, e ao chegar ao final reiniciar a contagem, por se tratar de uma lista
    novosDados[i] = f->dados;
  }

  free(f->dados); // aqui esvaziamos a fila original

  f->dados = novosDados; // passamos os novos valores para a nova lista
  f->p = 0;
  f->u = i; // o ultimo vai ser de acordo com a constagem do incremento do for, mas com margem menor do que o tamanho do vetor
  f->N = novoTamanho;
}

int desenfileira(fila *f, int *y){
  if(f->p == f->u){
    return 0;
  }

  *y = f->dados[f->p]; // pegamos o endereço do dado da primeira posição e passamos como refencia para o y

  f->p = f->p + 1; // atualizamos o primeiro elemento para o proximo

  return 1;
}