#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;




celula *enfileira (celula *f, int x){

    if(f->prox == NULL) return 0; //verifica se o proximo valor é nulo

    celula *nova; //criamos uma celula nova
    nova = malloc(sizeof(celula)); //redefinimos o tamanho da estrutura com a celula nova

    nova->dado = x; // a celula nova recebe o dado de x
    nova->prox = p->prox; // a celula nova vai apontar para onde seu antecessor apontava
    p-prox = nova;// e o seu antecessor vai apontara para a nova celula


    return 1;


}