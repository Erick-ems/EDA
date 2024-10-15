#include <stdio.h>

#define MAX_SIZE 61

int main() {
    int pairs[MAX_SIZE][2] = {0}; // Matriz para contar os pares de botas
    int size, pairs_count = 0;
    char foot;

    // Ler os dados das botas até o final do arquivo
    while (scanf("%d %c", &size, &foot) != EOF) {
        if (foot == 'D') {
            pairs[size][0]++; // Incrementa o contador de botas do pé direito do tamanho size
        } else if (foot == 'E') {
            pairs[size][1]++; // Incrementa o contador de botas do pé esquerdo do tamanho size
        }
    }

    // Contar o número total de pares corretos de botas
    for (int i = 30; i <= 60; i++) {
        pairs_count += pairs[i][0] < pairs[i][1] ? pairs[i][0] : pairs[i][1]; // Adiciona o menor número de botas do par
    }

    // Imprimir o número total de pares corretos de botas
    printf("%d\n", pairs_count);

    return 0;
}
