#include <stdio.h>

void troca(char c[], int i) {
    if (c[i] == '\0') {
        return;
    }

    if (c[i] == 'x') {
        c[i] = 'y';
    }

    troca(c, i + 1); 
}

int main() {
    char c[81];
    scanf("%s", c);

    troca(c, 0);

    printf("%s\n", c);

    return 0;
}
