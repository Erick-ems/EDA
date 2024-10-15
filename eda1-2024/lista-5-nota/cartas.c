#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = NULL;
}

void push(Stack *stack, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Erro: Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int main() {
    int n;
    scanf("%d", &n);

    Stack stack;
    initializeStack(&stack);

    // Empilhar as cartas
    for (int i = n; i >= 1; i--) {
        push(&stack, i);
    }

    printf("Cartas descartadas: ");
    while (stack.top != NULL && stack.top->next != NULL) {
        printf("%d, ", pop(&stack));
        int topData = pop(&stack);
        push(&stack, topData);
    }
    printf("\nCarta restante: %d\n", stack.top->data);

    return 0;
}
