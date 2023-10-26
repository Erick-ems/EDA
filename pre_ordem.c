#include <stdio.h>

typedef struct no {
	int dado;
	struct no *esq, *dir;


}no;
void pre_ordem(no *raiz){

  if(raiz == NULL) return; //Se a raiz for nula returna vazio

  no *stack[500]; //delacra a stack da memoria
  int top = -1; // ao delcarar o top da memoria como -1 dizemos que ela está vazia
  stack[++top] = raiz; //colocando o no da raiz na stack(pilha)

  while(top != -1){ //percorrer toda a arvore
    no *current = stack[top--];//colocando o no do topo na pilha
    printf("%d", current->dado); //printado/processando o no dado
    if(current->dir != NULL){//se o no lido for diferente de nulo
      stack[++top] = current->dir;//coloque seu filo da direita na fila
    }
    if(current->esq != NULL){// se tiver filho a esquerda
      stack[++top] = current->esq;// pegue o filho a esquerda e colque na pilha
    }
  }

}









////////////////////////////////////////////////////////////
