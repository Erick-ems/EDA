#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCOES 100
#define TAMANHO_PALAVRA 16

// Estrutura para representar uma entrada na tabela de dispersão
typedef struct EntradaTabela {
    int codigo;
    char palavra_chave[TAMANHO_PALAVRA];
    struct EntradaTabela *proximo;
} EntradaTabela;

// Função de hash simples
int hash(int codigo) {
    return codigo % MAX_INSTRUCOES;
}

// Função para inserir uma entrada na tabela de dispersão
void inserir(EntradaTabela **tabela, int codigo, char palavra_chave[TAMANHO_PALAVRA]) {
    int indice = hash(codigo);

    // Cria uma nova entrada
    EntradaTabela *nova_entrada = (EntradaTabela *)malloc(sizeof(EntradaTabela));
    nova_entrada->codigo = codigo;
    strcpy(nova_entrada->palavra_chave, palavra_chave);
    nova_entrada->proximo = NULL;

    // Insere a nova entrada na lista encadeada ordenada
    if (tabela[indice] == NULL || codigo < tabela[indice]->codigo) {
        nova_entrada->proximo = tabela[indice];
        tabela[indice] = nova_entrada;
    } else {
        EntradaTabela *atual = tabela[indice];
        while (atual->proximo != NULL && atual->proximo->codigo < codigo) {
            atual = atual->proximo;
        }
        nova_entrada->proximo = atual->proximo;
        atual->proximo = nova_entrada;
    }
}

// Função para buscar uma entrada na tabela de dispersão
char* buscar(EntradaTabela **tabela, int codigo) {
    int indice = hash(codigo);

    EntradaTabela *entrada_atual = tabela[indice];
    while (entrada_atual != NULL && entrada_atual->codigo <= codigo) {
        if (entrada_atual->codigo == codigo) {
            return entrada_atual->palavra_chave;
        }
        entrada_atual = entrada_atual->proximo;
    }

    return "undefined";
}

int main() {
    // Variáveis para armazenar as instruções
    int n, i;
    EntradaTabela *tabela[MAX_INSTRUCOES] = {NULL};

    // Lê o número de instruções
    scanf("%d", &n);

    // Lê as instruções e seus códigos correspondentes e insere na tabela de dispersão
    for (i = 0; i < n; i++) {
        int codigo;
        char palavra_chave[TAMANHO_PALAVRA];
        scanf("%d %s", &codigo, palavra_chave);
        inserir(tabela, codigo, palavra_chave);
    }

    // Variáveis para armazenar as consultas
    int codigo_consulta;

    // Realiza as consultas e imprime as palavras-chave correspondentes
    while (scanf("%d", &codigo_consulta) != EOF) {
        printf("%s\n", buscar(tabela, codigo_consulta));
    }

    return 0;
}
