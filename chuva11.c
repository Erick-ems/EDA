#include <stdio.h>

// Função para definir uma matriz bidimensional
void define_matrix(int mapa[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mapa[i * size + j]);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // Declaração de arrays bidimensionais para armazenar os mapas
    int mapa1[N][N];
    int mapa2[N][N];
    int resultado[N][N];

    // Leitura dos valores do primeiro mapa
    define_matrix((int *)mapa1, N);
    
    // Leitura dos valores do segundo mapa
    define_matrix((int *)mapa2, N);

    // Cálculo da soma dos mapas e impressão dos resultados
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = mapa1[i][j] + mapa2[i][j];
            printf("%d", resultado[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
