#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100001

// Estrutura de nó para a pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para verificar se as cadeias são bem definidas
char checkWellDefined(char *str) {
    Node* stack = NULL; // Pilha para armazenar os caracteres de abertura

    // Percorre a string
    for (int i = 0; str[i] != '\0'; i++) {
        // Se encontrar um caractere de abertura, empilha na pilha
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = str[i];
            newNode->next = stack;
            stack = newNode;
        }
        // Se encontrar um caractere de fechamento
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            // Se a pilha estiver vazia ou se o caractere de fechamento não corresponder ao topo da pilha
            if (stack == NULL || (str[i] == ')' && stack->data != '(') || (str[i] == ']' && stack->data != '[') || (str[i] == '}' && stack->data != '{')) {
                return 'N'; // Não é bem definido
            }
            // Caso contrário, desempilha o topo da pilha
            else {
                Node* temp = stack;
                stack = stack->next;
                free(temp);
            }
        }
    }

    // Se a pilha estiver vazia no final, a cadeia é bem definida
    if (stack == NULL) {
        return 'S';
    } else {
        return 'N';
    }
}

int main() {
    int T;
    char str[MAX_LENGTH];

    // Ler o número de instâncias
    scanf("%d", &T);

    // Iterar sobre cada instância
    for (int i = 0; i < T; i++) {
        // Ler a cadeia de caracteres
        scanf("%s", str);

        // Verificar se a cadeia é bem definida e imprimir o resultado
        printf("%c\n", checkWellDefined(str));
    }

    return 0;
}
