#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar as traduções
struct traducao {
    char japones[20];   // Palavra em japonês O(1)
    char portugues[80]; // Tradução em português O(1)
};

int main(void) {
    int T; // O(1)
    scanf("%d", &T); // Lê o número de instâncias O(1)

    for (int t = 0; t < T; t++) { // O(N)
        int pares, linhas;
        scanf("%d %d", &pares, &linhas); // Lê o número de pares de traduções e o número de linhas da letra da música

        struct traducao dicionario[pares]; // Cria um array de traduções com o tamanho especificado O(1)
        for (int i = 0; i < pares; i++) { // O(N)
            scanf("%s", dicionario[i].japones); // Lê a palavra em japonês O(N)
            getchar();  // Lê o espaço após a palavra em japonês O(1)
            fgets(dicionario[i].portugues, 80, stdin); // Lê a tradução em português O(N)
            dicionario[i].portugues[strcspn(dicionario[i].portugues, "\n")] = 0;  // Remove o \n do final da tradução O(1)
        }

        char linha[80];
        for (int i = 0; i < linhas; i++) { // O(N)
            fgets(linha, 80, stdin); // Lê uma linha da letra da música

            char *token = strtok(linha, " \n"); // Divide a linha em tokens (palavras), usando espaços e \n como delimitadores
            while (token != NULL) { //O(N)
                int encontrou = 0;
                for (int j = 0; j < pares; j++) { //O(N)
                    if (strcmp(token, dicionario[j].japones) == 0) { // Verifica se a palavra em japonês está no dicionário
                        printf("%s ", dicionario[j].portugues); // Imprime a tradução em português
                        encontrou = 1;
                        break;
                    }
                }
                if (encontrou == 0) {
                    printf("%s ", token); // Se a palavra não estiver no dicionário, imprime a palavra original
                }
                token = strtok(NULL, " \n"); // Continua a dividir a linha em tokens
            }
            printf("\n"); // Imprime uma nova linha após traduzir a linha da letra da música
        }
        if (t < T - 1) {
            printf("\n"); // Imprime uma linha em branco entre as instâncias, conforme especificado na saída
        }
    }

    return 0;
}
