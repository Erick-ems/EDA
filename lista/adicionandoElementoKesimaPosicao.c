#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula na lista
struct Node {
    int data;
    struct Node* next;
};

// Função auxiliar recursiva para inserir uma nova célula com conteúdo 'x' após a k-ésima célula
struct Node* insertAfterKthRecursive(struct Node* current, int k, int x) {
    // Caso base: Se chegarmos ao final da lista e a k-ésima célula não foi encontrada, retorna NULL
    if (current == NULL) {
        printf("A lista não possui uma k-ésima célula.\n");
        return NULL;
    }

    // Se encontrarmos a k-ésima célula, criamos a nova célula e a conectamos
    if (k == 1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = current->next;
        current->next = newNode;
    } else {
        // Caso contrário, continuamos a busca recursivamente
        current->next = insertAfterKthRecursive(current->next, k - 1, x);
    }

    return current;
}

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Cria uma lista encadeada com alguns elementos de exemplo
    head = insertAfterKthRecursive(head, 1, 10);
    head = insertAfterKthRecursive(head, 2, 20);
    head = insertAfterKthRecursive(head, 3, 30);

    // Imprime a lista resultante
    printList(head);

    return 0;
}
