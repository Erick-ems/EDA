#include <stdio.h>

int main() {
    int pares[61][2]; // Matriz para contar o número de botas para cada tamanho e pé (0 para esquerdo, 1 para direito)
    int M;
    char L;

    // Inicialize a matriz de contagem
    for (int i = 30; i <= 60; i++) {
        pares[i][0] = 0; // Esquerdo
        pares[i][1] = 0; // Direito
    }

    int totalPares = 0;

    while (scanf("%d %c", &M, &L) != EOF) {
        if (L == 'E') {
            pares[M][0]++;
        } else if (L == 'D') {
            pares[M][1]++;
        }
    }

    // Conta o número de pares corretos
    for (int i = 30; i <= 60; i++) {
        totalPares += (pares[i][0] < pares[i][1]) ? pares[i][0] : pares[i][1];
    }

    printf("%d\n", totalPares);

    return 0;
}