#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 8
#define MAX_COLS 8

// Estrutura para armazenar um movimento do cavalo
typedef struct {
    int row;
    int col;
} Move;

// Função para verificar se o movimento é válido
int isValidMove(int row, int col) {
    return (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS);
}

// Função para calcular o número mínimo de movimentos do cavalo entre dois quadrados
int minKnightMoves(char* from, char* to) {
    // Mapeamento das letras para índices de coluna (de 'a' para 0 até 'h' para 7)
    int colMap[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    // Coordenadas do quadrado de origem
    int fromRow = from[1] - '1';
    int fromCol = colMap[from[0] - 'a'];

    // Coordenadas do quadrado de destino
    int toRow = to[1] - '1';
    int toCol = colMap[to[0] - 'a'];

    // Movimentos possíveis do cavalo
    Move moves[8] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    // Inicialização da matriz de visitados e da fila
    int visited[MAX_ROWS][MAX_COLS];
    memset(visited, 0, sizeof(visited));

    // Inicialização da fila de movimentos
    Move queue[MAX_ROWS * MAX_COLS];
    int front = 0, rear = 0;
    queue[rear++] = (Move){fromRow, fromCol};
    visited[fromRow][fromCol] = 1;

    // Inicialização do número de movimentos
    int movesCount = 0;

    // Busca em largura
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Move current = queue[front++];

            // Verifica se chegamos ao quadrado de destino
            if (current.row == toRow && current.col == toCol) {
                return movesCount;
            }

            // Gera todos os movimentos possíveis do cavalo
            for (int j = 0; j < 8; j++) {
                int newRow = current.row + moves[j].row;
                int newCol = current.col + moves[j].col;

                // Verifica se o movimento é válido e não foi visitado
                if (isValidMove(newRow, newCol) && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    queue[rear++] = (Move){newRow, newCol};
                }
            }
        }
        // Incrementa o número de movimentos
        movesCount++;
    }

    // Se não for possível chegar ao quadrado de destino, retorna -1
    return -1;
}

int main() {
    char from[3], to[3];
    
    // Leitura da entrada até EOF
    while (scanf("%s %s", from, to) != EOF) {
        int moves = minKnightMoves(from, to);
        printf("To get from %s to %s takes %d knight moves.\n", from, to, moves);
    }

    return 0;
}
