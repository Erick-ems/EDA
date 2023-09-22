#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula da lista encadeada
struct Node {
    int data;             // Um campo para armazenar dados inteiros
    struct Node* next;    // Um ponteiro para a próxima célula na lista
};

// Função para contar o número de células de forma recursiva
int countCellsRecursive(struct Node* head) {
    if (head == NULL) {
        return 0; // Caso base: a lista está vazia, então retorna 0
    }

    int count = 1 + countCellsRecursive(head->next); // Chamada recursiva para a próxima célula
    free(head); // Libera a memória da célula atual
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
    int count = countCellsRecursive(head);  // Chama a função 'countCellsRecursive' com a lista encadeada como argumento
    printf("Número de células na lista encadeada: %d\n", count);  // Exibe o número de células na lista

    return 0;  // Retorna 0 para indicar que o programa foi concluído com sucesso
}
