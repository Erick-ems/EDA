#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para remover duplicatas de um array ordenado
int removeDuplicates(int *arr, int n) {
    if (n == 0 || n == 1)
        return n;

    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];

    arr[j++] = arr[n - 1];

    return j;
}

// Função para inserir um elemento de forma ordenada e sem repetidos
int insertUnique(int *arr, int n, int value) {
    int i;
    for (i = n - 1; (i >= 0 && arr[i] > value); i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = value;

    return n + 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar e remover duplicatas
    qsort(arr, N, sizeof(int), compare);
    N = removeDuplicates(arr, N);

    // Ajustar para número par de elementos
    if (N % 2 != 0) {
        arr = (int *)realloc(arr, (N + 1) * sizeof(int));
        arr[N++] = 1000000000;
    }

    // Calcular NMU e reinserir no vetor
    int *nmu = (int *)malloc((N / 2) * sizeof(int));
    int nmuCount = 0;
    for (int i = 0; i < N; i += 2) {
        int sum = arr[i] + arr[i + 1];
        nmu[nmuCount++] = sum;
    }

    // Inserir NMU no vetor original
    for (int i = 0; i < nmuCount; i++) {
        if (bsearch(&nmu[i], arr, N, sizeof(int), compare) == NULL) {
            arr = (int *)realloc(arr, (N + 1) * sizeof(int));
            N = insertUnique(arr, N, nmu[i]);
        }
    }

    // Ordenar o vetor resultante e remover duplicatas
    qsort(arr, N, sizeof(int), compare);
    N = removeDuplicates(arr, N);

    // Imprimir resultados
    for (int i = 0; i < N; i += 4) {
        printf("%d\n", arr[i]);
    }
    printf("Elementos: %d\n", N);

    // Liberar memória alocada
    free(arr);
    free(nmu);

    return 0;
}
