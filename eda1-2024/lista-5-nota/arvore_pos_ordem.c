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

// Função para percorrer a árvore em pós-ordem (postorder traversal) sem usar recursão
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Stack *stack1 = createStack(1000); // Criando uma pilha para armazenar os nós
    Stack *stack2 = createStack(1000); // Criando uma segunda pilha para armazenar os nós na ordem correta
    no *atual = raiz;

    // Empilhando todos os nós na primeira pilha
    push(stack1, atual);

    while (!isEmpty(stack1)) {
        // Desempilhar um nó da primeira pilha
        atual = pop(stack1);

        // Empilhar esse nó na segunda pilha
        push(stack2, atual);

        // Empilhar o nó esquerdo antes do nó direito para garantir a ordem correta
        if (atual->esq != NULL) {
            push(stack1, atual->esq);
        }
        if (atual->dir != NULL) {
            push(stack1, atual->dir);
        }
    }

    // Imprimir os nós da segunda pilha na ordem correta (pós-ordem)
    while (!isEmpty(stack2)) {
        atual = pop(stack2);
        printf("%d ", atual->dado);
    }

    free(stack1->array); // Liberar a memória alocada para a primeira pilha
    free(stack1);
    free(stack2->array); // Liberar a memória alocada para a segunda pilha
    free(stack2);
}