#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int value;
    int next_id;
    struct Node *next;
} Node;

Node* createNode(int id, int value, int next_id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    newNode->value = value;
    newNode->next_id = next_id;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, Node *newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printPistaOrder(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int id, value, next_id;
        scanf("%d %d %d", &id, &value, &next_id);
        Node *newNode = createNode(id, value, next_id);
        insertNode(&head, newNode);
    }

    Node *current = head;
    while (current != NULL) {
        if (current->next_id == -1) {
            break;
        }
        Node *next = head;
        while (next != NULL && next->id != current->next_id) {
            next = next->next;
        }
        current->next = next;
        current = next;
    }

    printPistaOrder(head);

    // Liberar memória
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
