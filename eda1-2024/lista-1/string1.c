#include <stdio.h>
#include <string.h>

int main() {



    char c[1000];
    scanf("%s", &c);


    int tamanho = 0;

    while(c[tamanho] != '\0'){
        tamanho++;
    }

    printf("%d\n", tamanho);


    return 0;
}