#include <stdio.h>



int main(){


    int N;
    scanf("%d", &N);


    //Declaração de array bidimensionais para armazenar os mapas

    int mapa1[N][N];
    int mapa2[N][N];

    //Leitura dos valores do primeiro mapa

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &mapa1[i][j]);
        }
    }

    //Leitura dos valores para o segundo mapa

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &mapa2[i][j]);
        }
    }


    int resultado[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            resultado[i][j] = mapa1[i][j] + mapa2[i][j];
        }
    }


    // para mostrar os resultados

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d", resultado[i][j]);
            if(j < N - 1){
                printf(" ");
            }
        }

        printf("\n");

    }

    return 0;
}