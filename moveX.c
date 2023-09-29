#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void troca(char c[], char v[], int tamanho, int i) {
    if (i < tamanho) {
        c[i] = v[i];
        troca(c, v, tamanho, i + 1);
    }
    return;
}

void moveX(char c[], int tamanho, int i, int lastIndex) {
    char v[101]; // Corrigido para ser um array de caracteres 'char'
    if (i >= tamanho) {
        troca(c, v, tamanho, 0);
        return;
    }

    if (c[i] != 'x') {
        v[i] = c[i]; 
        moveX(c, tamanho, i + 1, lastIndex);
    } else {
        v[lastIndex] = c[i];
        moveX(c, tamanho, i + 1, lastIndex + 1); 
    }
}





int main() {
    char c[101];
    scanf("%s", c);
    int tamanho = strlen(c);

    moveX(c, tamanho, 0, tamanho);

    printf("%s\n", c);

    return 0;
}