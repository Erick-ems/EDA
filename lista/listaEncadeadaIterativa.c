#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula da lista encadeada
struct Node {
    int data;             // Um campo para armazenar dados inteiros
    struct Node* next;    // Um ponteiro para a próxima célula na lista
};

// Função para contar o número de células de forma iterativa
int countCellsIterative(struct Node* head) {
    int count = 0;                 // Inicializa um contador para zero
    struct Node* current = head;   // Cria um ponteiro 'current' e o inicia com o início da lista

    while (current != NULL) {      // Enquanto 'current' não for nulo (ou seja, há células na lista)
        count++;                   // Incrementa o contador para cada célula encontrada
        struct Node* temp = current; // Armazena o endereço da célula atual em 'temp'
        current = current->next;     // Move 'current' para a próxima célula na lista
        free(temp);                  // Libera a memória da célula anterior
    }

    return count; // Retorna o número total de células na lista
}

int main() {
    // Exemplo de criação de uma lista encadeada simples
    struct Node* head = NULL;    // Cria um ponteiro 'head' para a lista e o inicializa como nulo
    struct Node* second = NULL;  // Cria um ponteiro 'second' para a segunda célula e o inicializa como nulo
    struct Node* third = NULL;   // Cria um ponteiro 'third' para a terceira célula e o inicializa como nulo

    head = (struct Node*)malloc(sizeof(struct Node));  // Aloca memória para a primeira célula e atribui o endereço a 'head'
    second = (struct Node*)malloc(sizeof(struct Node));  // Aloca memória para a segunda célula e atribui o endereço a 'second'
    third = (struct Node*)malloc(sizeof(struct Node));  // Aloca memória para a terceira célula e atribui o endereço a 'third'

    head->data = 1;             // Define o valor de 'data' da primeira célula como 1
    head->next = second;        // Define 'next' da primeira célula para apontar para 'second'

    second->data = 2;           // Define o valor de 'data' da segunda célula como 2
    second->next = third;       // Define 'next' da segunda célula para apontar para 'third'

    third->data = 3;            // Define o valor de 'data' da terceira célula como 3
    third->next = NULL;         // Define 'next' da terceira célula como nulo, indicando o final da lista

    // Chame a função para contar as células
    int count = countCellsIterative(head);  // Chama a função 'countCellsIterative' com a lista encadeada como argumento
    printf("Número de células na lista encadeada: %d\n", count);  // Exibe o número de células na lista

    // Libere a memória alocada para as células restantes
    free(head);  // Libera a memória da primeira célula
    free(second);  // Libera a memória da segunda célula
    free(third);  // Libera a memória da terceira célula

    return 0;  // Retorna 0 para indicar que o programa foi concluído com sucesso
}
