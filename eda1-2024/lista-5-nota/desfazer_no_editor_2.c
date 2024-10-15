#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100001

// Estrutura de pilha para verificar se as configurações estão fechadas corretamente
typedef struct Stack {
    char data[MAX_LENGTH];
    int top;
} Stack;

// Função para inicializar a pilha
void init(Stack* stack) {
    stack->top = -1;
}

// Função para empilhar um caractere na pilha
void push(Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

// Função para desempilhar um caractere da pilha
char pop(Stack* stack) {
    if (stack->top == -1) {
        return '\0'; // Pilha vazia
    }
    return stack->data[stack->top--];
}

// Função para verificar se as configurações estão fechadas corretamente
char checkFormatting(char* text) {
    Stack stack;
    init(&stack);
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '*' || text[i] == '/' || text[i] == '_') {
            if (text[i] == '/') {
                if (stack.top >= 0 && stack.data[stack.top] == '/') {
                    pop(&stack); // Fechar sublinhado
                } else {
                    push(&stack, text[i]); // Abrir sublinhado
                }
            } else {
                push(&stack, text[i]); // Abrir negrito ou itálico
            }
        } else if (text[i] == ' ') {
            // Ignorar espaços
        } else {
            if (stack.top >= 0 && ((text[i] == '*' && stack.data[stack.top] == '*') ||
                                   (text[i] == '/' && stack.data[stack.top] == '/') ||
                                   (text[i] == '_' && stack.data[stack.top] == '_'))) {
                pop(&stack); // Fechar negrito ou itálico
            } else {
                return 'E'; // Configuração fechada incorretamente
            }
        }
        i++;
    }
    return (stack.top == -1) ? 'C' : 'E'; // Se a pilha estiver vazia, todas as configurações foram fechadas corretamente
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Consumir o caractere de nova linha após a leitura de N

    char line[MAX_LENGTH];
    char result = 'C'; // Inicialmente assumimos que o texto está correto

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        result = checkFormatting(line);
        if (result == 'E') {
            break;
        }
    }

    printf("%c\n", result);

    return 0;
}
