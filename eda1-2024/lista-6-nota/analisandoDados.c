#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de cada sequência
typedef struct {
    int tamanho;
    char caractere;
    int posicao;
} Sequencia;

// Função para comparar duas sequências
int compararSequencias(const void *a, const void *b) {
    const Sequencia *sequenciaA = (const Sequencia *)a;
    const Sequencia *sequenciaB = (const Sequencia *)b;

    // Ordena por tamanho de sequência (decrescente) e, em caso de empate, por posição
    if (sequenciaA->tamanho != sequenciaB->tamanho) {
        return sequenciaB->tamanho - sequenciaA->tamanho;
    } else {
        return sequenciaA->posicao - sequenciaB->posicao;
    }
}

// Função para analisar e imprimir as sequências
void analisarSequencias(char *string) {
    int n = strlen(string);
    Sequencia *sequencias = (Sequencia *)malloc(n * sizeof(Sequencia));
    if (sequencias == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    int contador = 0;
    int i = 0;
    while (i < n) {
        char caractereAtual = string[i];
        int tamanhoAtual = 0;
        int posicaoAtual = i;

        // Conta o tamanho da sequência do caractere atual
        while (i < n && string[i] == caractereAtual) {
            tamanhoAtual++;
            i++;
        }

        // Armazena a sequência encontrada
        sequencias[contador].tamanho = tamanhoAtual;
        sequencias[contador].caractere = caractereAtual;
        sequencias[contador].posicao = posicaoAtual;
        contador++;
    }

    // Ordena as sequências
    qsort(sequencias, contador, sizeof(Sequencia), compararSequencias);

    // Imprime as sequências ordenadas
    for (int j = 0; j < contador; j++) {
        printf("%d %c %d\n", sequencias[j].tamanho, sequencias[j].caractere, sequencias[j].posicao);
    }

    free(sequencias);
}

int main() {
    char string[100000];
    scanf("%s", string);
  
    analisarSequencias(string);
    return 0;
}