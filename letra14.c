#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char linha[1001]; // Assumindo que a linha de entrada pode ter no máximo 1000 caracteres

    char l[3];
    fgets(l, sizeof(l), stdin);

    fgets(linha, sizeof(linha), stdin);
    linha[strcspn(linha, "\n")] = '\0'; // Remove o caractere de nova linha se presente

    int numPalavras = 0;
    int numLetras = 0;
    bool dentroDaPalavra = false;



    for(int i = 0; linha[i] != '\0'; i++){
        if(isalpha(linha[i])){
            if(!dentroDaPalavra){
                dentroDaPalavra = true;
                numPalavras++;
            }

            if(tolower(linha[i]) == l[0] && numLetras == 0){
                numLetras += 1;
            }
        }else{
            dentroDaPalavra = false;
        }
    }


    float conta = ((float)numLetras * 100)/numPalavras;

    printf("%.1f\n", conta);

    return 0;
}