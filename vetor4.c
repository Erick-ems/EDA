#include <stdio.h>


int main(){


    int N; // inicia a váriavel N
    scanf("%d", &N); // escaneia o inteiro e N e atribui um valor para ela

    
    int vetor[N]; // declaramos um vetor de tamanho N;
    int indicePar[N];
    int indiceImpar[N];

    int countPar = 0;
    int countImpar = 0;


    for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] % 2 == 0){
            indicePar[countPar] = i;
            countPar++;
        }else{
            indiceImpar[countImpar] = i;
            countImpar++;
        }
    }

    for (int i = 0; i < countPar; i++) {
        printf("%d ", indicePar[i]);
    }
    printf("\n");
    for (int i = 0; i < countImpar; i++) {
        printf("%d ", indiceImpar[i]);
    }
    printf("\n");





    return 0;
}