#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int pilha[n]; // Cria um vetor para representar a pilha de cartas
    int topo = 0; // Índice do topo da pilha

    // Inicializa a pilha com as cartas de 1 até n
    for (int i = 0; i < n; i++) {
        pilha[i] = i + 1;
    }

    printf("Cartas descartadas: ");
    int descartadas[n - 1]; // Para armazenar as cartas descartadas
    int j = 0; // Índice para o vetor de cartas descartadas

    while (topo < n) {
        if (topo > 0) {
            descartadas[j++] = pilha[topo - 1]; // Carta descartada
            topo--;
        }
        if (topo < n - 1) {
            pilha[topo] = pilha[topo + 1]; // Move a próxima carta para o topo
            topo++;
        }
    }

    // Imprime as cartas descartadas
    for (int i = 0; i < n - 1; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", descartadas[i]);
    }
    printf("\nCarta restante: %d\n", pilha[0]);

    return 0;
}