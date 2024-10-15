#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int col;
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node **rows;
    int m; // Número de linhas da matriz
    int n; // Número de colunas da matriz
} SparseMatrix;

SparseMatrix* createSparseMatrix(int m, int n) {
    SparseMatrix *matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if (matrix == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    matrix->rows = (Node**)calloc(m, sizeof(Node*));
    if (matrix->rows == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    matrix->m = m;
    matrix->n = n;

    return matrix;
}

void insertElement(SparseMatrix *matrix, int row, int col, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;

    if (matrix->rows[row] == NULL) {
        matrix->rows[row] = newNode;
    } else {
        Node *current = matrix->rows[row];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void multiplyMatrixVector(SparseMatrix *matrix, int *vector, int *result) {
    for (int i = 0; i < matrix->m; i++) {
        Node *current = matrix->rows[i];
        while (current != NULL) {
            result[i] += current->val * vector[current->col];
            current = current->next;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    SparseMatrix *matrix = createSparseMatrix(m, n);

    int row, col, val;
    while (scanf("%d %d %d", &row, &col, &val) == 3 && row != -1 && col != -1 && val != -1) {
        insertElement(matrix, row, col, val);
    }

    int *vector = (int*)malloc(n * sizeof(int));
    if (vector == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    int *result = (int*)calloc(m, sizeof(int));
    if (result == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    multiplyMatrixVector(matrix, vector, result);

    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    // Liberar memória
    for (int i = 0; i < m; i++) {
        Node *current = matrix->rows[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix->rows);
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
