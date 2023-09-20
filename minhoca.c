#include <stdio.h>




int main(){

    int N,M;
    int maiorSoma = 0;  
    scanf("%d %d", &N, &M); //escaneia o valor de linha e colunas


    int matriz[N][M]; // define o tamanho da matriz com os valores recebidos


    // para cada posição i e j da matriz, linha e coluna, e recebe seu valor
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &matriz[i][j]);
        }
    }


    for(int j = 0; j < M; j++){     //para cada valor da coluna 
        int somaColuna = 0;         // declara a variavel que vai armazenar a soma
        
        // nesse bloco ele mantém a coluna e verifica cada linha da coluna
        // e soma seus elementos da coluna
        // armazena esse valor e pula para proxima coluna
        // faz o mesmo processo
        // compara qual valor é o maior
        for(int i = 0; i < N; i++){
            somaColuna += matriz[i][j];
        }
        if(somaColuna > maiorSoma){
            maiorSoma = somaColuna;
        }
    }

    printf("%d\n", maiorSoma);


    return 0;
}