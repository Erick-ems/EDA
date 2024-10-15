//Hello guice, my name is erick, and today ill solve that problem, 
//the problem consists in find a number on struct how is equal the value
//using linked-lists

#include <stdio.h> // the first steap is import the bibliotec

typedef struct celula // define the struct with your types
{
  int dado;
  struct celula *prox;
} celula;

celula *busca_rec(celula *le, int x) { // in that we will do the recursive version
    if (le == NULL || le->dado == x)
        return le;
    else
        return busca_rec(le->prox, x);
}

celula *busca(celula *le, int x) { // and that the interactive version
    celula *p;
    for (p = le; p != NULL && p->dado != x; p = p->prox);
    return p;
}
