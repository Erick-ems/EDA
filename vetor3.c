#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    int par[N];
    int impar[N];

    int countPar = 0;
    int countImpar = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]); // Corrigir o scanf aqui

        if (vetor[i] % 2 == 0) {
            par[countPar] = vetor[i];
            countPar++;
        } else {
            impar[countImpar] = vetor[i];
            countImpar++;
        }
    }

    for (int i = 0; i < countPar; i++) {
        printf("%d ", par[i]); // Adicione um espaço após cada número
    }
    printf("\n");
    for (int i = 0; i < countImpar; i++) {
        printf("%d ", impar[i]); // Adicione um espaço após cada número
    }
    printf("\n");

    return 0;
}
