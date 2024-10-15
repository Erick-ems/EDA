#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101

// Estrutura de nó para a lista encadeada de alterações
typedef struct Node {
    char change[MAX_LENGTH];
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(char* change) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        strcpy(newNode->change, change);
        newNode->next = NULL;
    }
    return newNode;
}

// Função para inserir uma nova alteração na lista
void insert(Node** head, char* change) {
    Node* newNode = createNode(change);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

// Função para desfazer a última alteração na lista
char* undo(Node** head) {
    if (*head == NULL) {
        return "NULL";
    } else {
        Node* temp = *head;
        *head = (*head)->next;
        char* change = temp->change;
        free(temp);
        return change;
    }
}

int main() {
    Node* head = NULL;
    char command[MAX_LENGTH];

    // Leitura da entrada até EOF
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "desfazer") == 0) {
            printf("%s\n", undo(&head));
        } else {
            char change[MAX_LENGTH];
            scanf("%s", change);
            insert(&head, change);
        }
    }

    // Libera a memória da lista encadeada
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
