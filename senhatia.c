#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*
int main(){


    int N, M, A, K;


    scanf("%d %d %d %d", &N, &M, &A, &K);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char texto[100];    

    fgets(texto, sizeof(texto), stdin);


    int tamanho = strlen(texto);

    int maiusculas = 0;
    int minusculas = 0;
    int numeros = 0;

    for(int i = 0; i < tamanho; i++){
        if(isupper(texto[i])){
            maiusculas++;
        }else if(islower(texto[i])){
            minusculas++;
        }else if(isdigit(texto[i])){
            numeros++;
        }
    }


    if(tamanho >= N && minusculas >= M && A == maiusculas && K = numeros){
        printf("Ok =/\n");
    }else{
        printf("Ufa :)\n");
    }

    return 0;
}
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int N, M, A, K;
    scanf("%d %d %d %d", &N, &M, &A, &K);

    // Limpa o buffer de entrada para evitar quebras de linha pendentes
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char senha[1001]; // Assumindo que a senha pode ter no máximo 1000 caracteres
    fgets(senha, sizeof(senha), stdin);

    int tamanho = strlen(senha);
    int maiusculas = 0;
    int minusculas = 0;
    int numeros = 0;

    for (int i = 0; i < tamanho; i++) {
        char caractere = senha[i];
        if (isupper(caractere)) {
            maiusculas++;
        } else if (islower(caractere)) {
            minusculas++;
        } else if (isdigit(caractere)) {
            numeros++;
        }
    }

    if (tamanho >= N && maiusculas >= A && minusculas >= M && numeros >= K) {
        printf("Ok =/\n");
    } else {
        printf("Ufa :)\n");
    }

    return 0;
}
