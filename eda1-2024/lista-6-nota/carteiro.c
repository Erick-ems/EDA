#include <stdio.h>
#include <stdlib.h>

// Função para calcular o tempo necessário para entregar todas as encomendas
int calcularTempo(int *rua, int *encomendas, int n, int m) {
    int tempo_total = 0;
    int posicao_atual = 0;

    // Para cada encomenda
    for (int i = 0; i < m; i++) {
        // Encontra a posição da próxima casa com uma encomenda
        int proxima_casa = 0;
        for (int j = posicao_atual; j < n; j++) {
            if (rua[j] == encomendas[i]) {
                proxima_casa = j;
                break;
            }
        }

        // Calcula a distância entre a posição atual e a próxima casa com encomenda
        tempo_total += abs(proxima_casa - posicao_atual);
        posicao_atual = proxima_casa;
    }

    return tempo_total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Lê a rua e as encomendas
    int rua[n];
    int encomendas[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &rua[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &encomendas[i]);
    }

    // Calcula e imprime o tempo necessário para entregar todas as encomendas
    int tempo_total = calcularTempo(rua, encomendas, n, m);
    printf("%d\n", tempo_total);

    return 0;
}

