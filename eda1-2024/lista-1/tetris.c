#include <stdio.h>

void deleteUns(int m, int matriz[m][m]){
    int ultimoIndice = m - 1;
    int linhaContemApenasUns = 1;
    for(int j = 0; j < m; j++){
        if(matriz[ultimoIndice][j] != 1) {
            linhaContemApenasUns = 0;
            break;
        }
    }
    if(linhaContemApenasUns) {
        for(int j = 0; j < m; j++){
            matriz[ultimoIndice][j] = 0;
        }
    }
}

void desceUns(int m, int matriz[m][m]){
    for(int j = 0; j < m; j++){
        int indiceUltimoZero = -1;
        for(int i = m - 1; i >= 0; i--){
            if(matriz[i][j] == 0){
                indiceUltimoZero = i;
            } else if(indiceUltimoZero > -1){
                matriz[indiceUltimoZero][j] = 1;
                matriz[i][j] = 0;
                indiceUltimoZero--;
            }
        }
    }
}

int matrizPronta(int m, int matriz[m][m]){
    for(int j = 0; j < m; j++){
        for(int i = m - 1; i > 0; i--){
            if(matriz[i][j] == 0 && matriz[i - 1][j] == 1){
                return 0;
            }
        }
    }
    return 1;
}

void imprimeMatriz(int m, int matriz[m][m]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Quebra de linha após cada matriz
}

int main(void){
    int m;
    scanf("%d", &m);
    int matriz[m][m];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int matrizOriginal[m][m];
    int mudanca;
    do {
        mudanca = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                matrizOriginal[i][j] = matriz[i][j];
            }
        }

        deleteUns(m, matriz);
        imprimeMatriz(m, matriz);

        if(matrizPronta(m, matriz)) break;

        desceUns(m, matriz);
        imprimeMatriz(m, matriz);

        if(matrizPronta(m, matriz)) break;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(matrizOriginal[i][j] != matriz[i][j]){
                    mudanca = 1;
                    break;
                }
            }
            if(mudanca) break;
        }
    } while(mudanca);

    return 0;
}
