#include <stdio.h>



int main(){

    int N, M;
    scanf("%d", &N);
    int cont = 0;

    int vetor[N];


    for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &M);


    for(int i = 0; i < N; i++){
        if(M == vetor[i]){
            cont++;
        }else{
            cont;
        }
    }

    if(cont == 1){
        printf("pertence\n");
    }else{
        printf("nao pertence\n");
    }


    return 0;
}