#include <stdio.h>

int main(){

    int N; // inicia a váriavel N
    scanf("%d", &N); // escaneia o inteiro e N e atribui um valor para ela



    
int vetor[N]; // declaramos um vetor de tamanho N;
    int menor_elemento = 1000001; //inicializamos com um valor alto para garantir que qualqer valor seja menor
    int indice_menor = -1; // atribuimos menos 1 para podermos fazer a contegem do indice do elemento


    for(int i = 0; i < N; i++){             //inicia um laço for para percorrer todo o vetor
        scanf("%d", &vetor[i]);             //recebe uma variavel e aloca ela em uma posição do vetor
        if(vetor[i] < menor_elemento){      // verifica se o o valor colocado é realmente o menor valor 
            menor_elemento = vetor[i];      // se for o valor do menor elemento é atualizado
            indice_menor = i;               // e o indice menor recebe "a posição dele", só que essa posição na verdade é a contagem do incremento
        }

    }


    printf("%d\n", indice_menor);            // retorna omenor indices

    return 0;
}