#include <stdio.h>

int main() {
    int caso = 1; // Contador de casos de teste
    int P, R; // Quantidade inicial de participantes e quantidade de rodadas
    while (1) {
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) {
            break; // Fim da entrada
        }

        int fila[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        int vencedor = 0; // Identificador do vencedor

        for (int r = 0; r < R; r++) {
            int N, J;
            scanf("%d %d", &N, &J);

            int acoes[P]; // Vetor de ações dos participantes
            for (int i = 0; i < N; i++) {
                scanf("%d", &acoes[i]);
            }

            if (vencedor == 0) { // Se o vencedor já foi determinado, pule as rodadas restantes
                int vivo = 0; // Contador de participantes vivos
                int eliminados = 0; // Contador de participantes eliminados

                for (int i = 0; i < N; i++) {
                    if (acoes[i] == 1) {
                        vivo++;
                    } else {
                        eliminados++;
                    }
                }

                if (eliminados == N) {
                    // Todos foram eliminados, o jogo termina
                    vencedor = fila[0];
                } else if (vivo == N) {
                    // Ninguém foi eliminado, o jogo continua
                } else if (J == 0) {
                    // Ordem "morto" do chefe
                    for (int i = 0; i < N; i++) {
                        if (acoes[i] == 1) {
                            vencedor = fila[i];
                            break;
                        }
                    }
                } else {
                    // Ordem "vivo" do chefe
                    for (int i = N - 1; i >= 0; i--) {
                        if (acoes[i] == 1) {
                            vencedor = fila[i];
                            break;
                        }
                    }
                }
            }
        }

        printf("Teste %d\n%d\n\n", caso, vencedor);
        caso++;
    }

    return 0;
}