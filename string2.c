#include <stdio.h>
#include <string.h>

int main() {
    char c[100];

    // Remove this line as it's not needed
    // int tamanho = sizeof(c);
   
    // Use %s in scanf to read a string into 'c' without the '&' symbol
    scanf("%s", c);

    int tamanho = strlen(c); // Calculate the length of the input string
    
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", c[i]); // Use %c to print individual characters
    }
    printf("\n");

    return 0;
}
