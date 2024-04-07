#include <stdio.h>

int repetidos(int v[10000], int qtd, int index) {
    int count = 0;
    int numero = v[index];

    for (int i = 0; i < qtd; i++) {
        if (v[i] == numero) {
            count++;
        }
    }
    count = count - 1;

    return count;
}
