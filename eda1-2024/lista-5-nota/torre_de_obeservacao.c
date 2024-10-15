#include <stdio.h>

#define MAX_N 102
#define MAX_HEIGHT 100

typedef struct {
    int x;
    int y;
} Tower;

int visualize_areas(int N, int M, char terrain[MAX_N][MAX_N], Tower towers[], int heights[], int T) {
    int i, j, k;
    int visible_count = 0;
    int visible[MAX_N][MAX_N] = {0}; // Matriz para marcar as áreas visíveis

    // Função para verificar se as coordenadas (x, y) estão dentro dos limites do terreno
    int is_valid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    // Função para marcar as áreas visíveis a partir de uma torre
    void mark_visible(int x, int y, int height) {
        int dx, dy;
        for (dx = -height; dx <= height; dx++) {
            for (dy = -height; dy <= height; dy++) {
                if (dx * dx + dy * dy <= height * height) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (is_valid(nx, ny)) {
                        visible[nx][ny] = 1; // Marca a posição como visível
                    }
                }
            }
        }
    }

    // Marcar as áreas visíveis para cada torre
    for (i = 0; i < T; i++) {
        mark_visible(towers[i].x, towers[i].y, heights[i]);
    }

    // Contar e atualizar as áreas visíveis no terreno
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (terrain[i][j] == '#' && !visible[i][j]) {
                terrain[i][j] = '.';
            } else if (terrain[i][j] == '#' && visible[i][j]) {
                visible_count++;
            }
        }
    }

    return visible_count;
}

// Função para imprimir o terreno
void print_terrain(int N, int M, char terrain[MAX_N][MAX_N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%c", terrain[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, M, T, i;
    char terrain[MAX_N][MAX_N];
    Tower towers[MAX_N * MAX_N];
    int heights[MAX_N * MAX_N];

    // Ler o tamanho do terreno
    scanf("%d %d", &N, &M);

    // Ler o terreno
    for (i = 0; i < N; i++) {
        scanf("%s", terrain[i]);
    }

    // Ler o número de torres
    scanf("%d", &T);

    // Ler as coordenadas e alturas das torres
    for (i = 0; i < T; i++) {
        scanf("%d", &towers[i].x);
        scanf("%d", &towers[i].y);
        scanf("%d", &heights[i]);
    }

    // Calcular e imprimir as áreas visíveis
    int visible_count = visualize_areas(N, M, terrain, towers, heights, T);
    printf("%d\n", visible_count);
    print_terrain(N, M, terrain);

    return 0;
}
