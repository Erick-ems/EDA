#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura para os nós da árvore
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Definição da estrutura para os nós da pilha
typedef struct {
    no *node;
} StackNode;

// Definição da estrutura da pilha
typedef struct {
    int capacity;
    int top;
    StackNode *array;
} Stack;

// Função para criar uma pilha
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (StackNode *)malloc(stack->capacity * sizeof(StackNode));
    return stack;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Função para empilhar um nó na pilha
void push(Stack *stack, no *node) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top].node = node;
}

// Função para desempilhar um nó da pilha
no *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--].node;
}

// Função para percorrer a árvore em pré-ordem (preorder traversal) sem usar recursão
void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Stack *stack = createStack(1000); // Criando uma pilha para armazenar os nós
    no *atual = raiz;

    // Empilhando o nó raiz
    push(stack, atual);

    while (!isEmpty(stack)) {
        // Desempilhando um nó
        atual = pop(stack);

        // Imprimindo o valor do nó
        printf("%d ", atual->dado);

        // Empilhando o nó direito antes do nó esquerdo para garantir a ordem correta
        if (atual->dir != NULL) {
            push(stack, atual->dir);
        }
        if (atual->esq != NULL) {
            push(stack, atual->esq);
        }
    }

    free(stack->array); // Liberando a memória alocada para a pilha
    free(stack);
}