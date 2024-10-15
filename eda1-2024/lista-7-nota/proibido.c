#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH 140003 // Um valor primo um pouco maior que 140000 para a tabela hash

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* tabela_hash[MAX_HASH];

unsigned int hash(int chave) {
    return chave % MAX_HASH;
}

void inserir(int valor) {
    unsigned int indice = hash(valor);
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

int buscar(int valor) {
    unsigned int indice = hash(valor);
    No* atual = tabela_hash[indice];
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; // Encontrado
        }
        atual = atual->prox;
    }
    return 0; // Não encontrado
}

void limpar_tabela() {
    for (int i = 0; i < MAX_HASH; i++) {
        No* atual = tabela_hash[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabela_hash[i] = NULL;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        int pi;
        if (scanf("%d", &pi) != 1) return 1;
        inserir(pi);
    }

    int num;
    while (scanf("%d", &num) != EOF) {
        if (buscar(num)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    limpar_tabela();
    return 0;
}
