#include <stdio.h>

int main() {
    int P, R;
    int caso = 1;

    while (scanf("%d %d", &P, &R) == 2 && (P != 0 || R != 0)) {
        int fila[P];
        int participantes = P;

        // Ler a fila inicial
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        // Simular as rodadas
        for (int i = 0; i < R; i++) {
            int N, J;
            scanf("%d %d", &N, &J);
            int acao[N];
            int eliminados = 0;

            for (int j = 0; j < N; j++) {
                scanf("%d", &acao[j]);
                if (acao[j] == J) {
                    eliminados++;
                }
            }

            participantes -= eliminados;

            // Reorganizar a fila
            int novaFila[P];
            int indice = 0;

            for (int j = 0; j < P; j++) {
                if (fila[j] != J) {
                    novaFila[indice++] = fila[j];
                }
            }

            for (int j = 0; j < P - participantes; j++) {
                novaFila[indice++] = fila[j];
            }

            for (int j = 0; j < participantes; j++) {
                fila[j] = novaFila[j];
            }
        }

        // Encontrar o vencedor
        printf("Teste %d\n", caso++);
        printf("%d\n\n", fila[0]);
    }

    return 0;
}
