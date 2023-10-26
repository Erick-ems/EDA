void em_ordem(no *raiz){   // declaro a raiz que é por onde vai começar arvore
  if(raiz == NULL) return;// se a reaix for nula retorne vazio ou zero vai depender da questão

  no *stack[500]; // criamos uma pilha de tamanho 500 na memoria
  int top = -1; // declaramos o top como -1 ou seja consideramos ele vazio
  no *current = raiz; // assumimos que o noi atual current no é a raiz

  while (top != -1 || current != NULL) { // enquanto o top foi diferente de vazio ou o no atual for diferente de nullo ou seja vai percorrrer toda a arvore
    while (current != NULL) { // enquanto o no atual foi diferente de nulo
      stack[++top] = current; // a gente empilha o no atual
      current = current->esq; // o no atual vai estar a esquerada inicialmente, ou seja ele vai percorre a esqueda primeiro
    }
    current = stack[top--]; // desempilhar esse no a esquerda
    printf("%d ", current->dado);// processar este dado
    current = current->dir;// e epulhar o no a direita
  }
}
