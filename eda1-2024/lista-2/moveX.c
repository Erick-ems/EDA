#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char v[101];
    int count = 0;
    char c;
    int i = 0;
    int count2 = 0;

    while((c = getchar()) != '\n' && c != EOF) {
        v[count] = c;
        count++;
        count2++;
    }

    i = 0;
    while(i < count) {
        if(v[i] == 'x') {
            for(int j = i; j < count - 1; j++) {
                char temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
            count--; // decrementa o contador para evitar o último 'x' que já foi movido
        } else {
            i++; // só incrementa o i se não movermos um 'x'
        }
    }

    for(int i = 0; i < count2; i++) {
        printf("%c", v[i]);
    }

    printf("\n");

    return 0;
}
