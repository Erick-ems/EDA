#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para os nós da árvore
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Função para inserir um novo nó na árvore
no *inserir(no *raiz, int valor) {
    // Se a árvore estiver vazia, crie um novo nó com o valor dado
    if (raiz == NULL) {
        no *novo = (no *)malloc(sizeof(no));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    // Caso contrário, insira recursivamente no ramo direito ou esquerdo, conforme o valor
    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->dado) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

// Função para percorrer a árvore em pré-ordem (preorder traversal)
void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d ", raiz->dado);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

// Função para percorrer a árvore em ordem (inorder traversal)
void em_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    em_ordem(raiz->esq);
    printf("%d ", raiz->dado);
    em_ordem(raiz->dir);
}

// Função para percorrer a árvore em pós-ordem (postorder traversal)
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->dado);
}

int main() {
    int valor;
    no *raiz = NULL;

    // Ler os números da entrada padrão e inseri-los na árvore
    while (scanf("%d", &valor) != EOF) {
        raiz = inserir(raiz, valor);
    }

    // Percorrer a árvore em pré-ordem
    printf("Pre-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    // Percorrer a árvore em ordem
    printf("Em ordem: ");
    em_ordem(raiz);
    printf("\n");

    // Percorrer a árvore em pós-ordem
    printf("Pos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Liberar a memória alocada para a árvore
    // Note que isso não é estritamente necessário para o exemplo simples aqui, mas é uma boa prática
    free(raiz);

    return 0;
}
