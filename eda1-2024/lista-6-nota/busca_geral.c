#include <stdio.h>
#include <stdlib.h>

// Estrutura para os itens na tabela hash
typedef struct HashItem {
    int key; // chave (o número em si)
    int value; // valor (índice do número no array)
    struct HashItem* next; // próximo item na lista de colisão
} HashItem;

#define HASH_SIZE 100003 // Tamanho da tabela hash, um número primo grande para reduzir colisões

// Função de hash simples
unsigned int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// Função para adicionar um item na tabela hash
void hash_add(HashItem* hash_table[], int key, int value) {
    unsigned int index = hash(key);
    HashItem* new_item = (HashItem*)malloc(sizeof(HashItem));
    new_item->key = key;
    new_item->value = value;
    new_item->next = hash_table[index];
    hash_table[index] = new_item;
}

// Função para buscar um item na tabela hash
int hash_find(HashItem* hash_table[], int key) {
    unsigned int index = hash(key);
    HashItem* item = hash_table[index];
    while (item != NULL) {
        if (item->key == key) {
            return item->value;
        }
        item = item->next;
    }
    return -1; // não encontrado
}

// Função para liberar a memória da tabela hash
void hash_free(HashItem* hash_table[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashItem* item = hash_table[i];
        while (item != NULL) {
            HashItem* temp = item;
            item = item->next;
            free(temp);
        }
    }
}

int main() {
    int N, M;

    // Leitura de N e M
    scanf("%d %d", &N, &M);

    int* v = (int*)malloc(N * sizeof(int));
    int* buscas = (int*)malloc(M * sizeof(int));

    // Leitura dos N números que compõem o conjunto de dados
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    // Leitura dos M números a serem buscados
    for (int i = 0; i < M; i++) {
        scanf("%d", &buscas[i]);
    }

    // Criação da tabela hash
    HashItem* hash_table[HASH_SIZE] = {0};

    // Adicionando elementos do conjunto na tabela hash
    for (int i = 0; i < N; i++) {
        hash_add(hash_table, v[i], i);
    }

    // Para cada número a ser buscado, procurar na tabela hash e imprimir o resultado
    for (int i = 0; i < M; i++) {
        int resultado = hash_find(hash_table, buscas[i]);
        printf("%d\n", resultado);
    }

    // Liberação da memória
    hash_free(hash_table);
    free(v);
    free(buscas);

    return 0;
}
