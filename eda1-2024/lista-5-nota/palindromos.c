#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Função para verificar se a string é um palíndromo
int isPalindrome(char str[], int len) {
    int i, j;

    // Percorre a string até a metade
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Se os caracteres não correspondem, não é um palíndromo
        }
    }

    return 1; // Se passar pelo loop sem retornar 0, é um palíndromo
}

int main() {
    int N;
    char sequence[MAX_LENGTH];

    // Ler o tamanho da sequência
    scanf("%d", &N);

    // Ler a sequência de caracteres
    scanf("%s", sequence);

    // Verificar se a sequência é um palíndromo e imprimir o resultado
    if (isPalindrome(sequence, N)) {
        printf("1\n"); // É um palíndromo
    } else {
        printf("0\n"); // Não é um palíndromo
    }

    return 0;
}
