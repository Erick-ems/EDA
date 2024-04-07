#include <stdio.h>
#include <stdlib.h>

char* vetor[1000];

void mark(int m, int h) {
    vetor[m] = malloc(h + 1);
    for(int i = 0; i < h; i++) {
        vetor[m][i] = '-';
    }
    vetor[m][h] = '\0';
}

void rule(int p, int r, int h) {
    int m = (p + r) / 2;
    if(h > 0) {
        rule(p, m, h - 1);
        mark(m, h);
        rule(m, r, h - 1);
    }
}

void Rule(int n) {
    int pot = 1;
    for(int i = 0; i < n; i++) {
        pot *= 2;
    }
    rule(0, pot, n);
}

int main(void) {
    int n;
    scanf("%d", &n);
    Rule(n);
    for(int i = 0; i < (1 << n); i++) {
        if(vetor[i]) {
            printf(".%s\n", vetor[i]);
        }
    }
    return 0;
}
