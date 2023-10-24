#include <stdio.h>
#include <string.h>

void contrario(char c[], char v[], int i, int tamanho) {
    if (i >= tamanho) {
        v[i] = '\0';
        return;
    }

    v[i] = c[tamanho - i - 1];
    contrario(c, v, i + 1, tamanho);
}

int main() {
    char c[501];
    char v[501];
    

    scanf("%s", c);

    int tamanho = strlen(c);

    contrario(c, v, 0, tamanho);

    printf("%s\n", v);

    return 0;
}
