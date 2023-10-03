#include <stdio.h>

int contarPares(char str[], int i) {
    // Condição de parada: chegou ao final da string ou após o último caractere
    if (str[i] == '\0' || str[i + 1] == '\0') {
        return 0;
    }

    // Verifica se há um par de caracteres
    if (str[i] == str[i + 2]) {
        return 1 + contarPares(str, i + 1);
    } else {
        return contarPares(str, i + 1);
    }
}

int main() {
    char str[201];
    scanf("%s", str);

    int qtdPares = contarPares(str, 0);

    printf("%d\n", qtdPares);

    return 0;
}
