void pos_ordem(no *raiz){ // declarmamos a raiz com no 
  if(raiz == NULL) return; // se a raiz for nula retorne o que a questão pedir;

  no *stack1[500]; // criamos uma pilha
  no *stack2[500]; // criamos outra pilha
  int top1 = -1; // definimo o top da pilha 1 como -1 o que siginifica que esta vazio
  int top2 = -1;// definimo o top da pilha 2 como -1 o que siginifica que esta vazio

  stack1[++top1] = raiz; // empilhamos a raiz na pilha 1

  while (top1 != -1) { // utilizaremos a pilha 1 como refrencia caso o top não seja vazio
    no *current = stack1[top1--]; // vamos desempilhar o no atual da pilha 1
    stack2[++top2] = current; //vamos empilhar este no na pilha 2

    if (current->esq) {
      stack1[++top1] = current->esq; // se este no tiver um filho a esqueda empilha ele
    }
    if (current->dir) {
      stack1[++top1] = current->dir; // se tiver a direita empilha ele
    }
  }
  while (top2 != -1) { //enquanto o top não for vazio
    no *current = stack2[top2--]; // desempilhe o no
    printf("%d ", current->dado); // mostre este no processado
    
  }
}
