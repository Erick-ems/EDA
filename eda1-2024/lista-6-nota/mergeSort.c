#include <stdio.h>
#include <stdlib.h>

typedef int Item;

void merge(Item *v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Item *L = (Item *)malloc(n1 * sizeof(Item));
    Item *R = (Item *)malloc(n2 * sizeof(Item));

    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Item *v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int n;
    
    // Leitura da quantidade de elementos
    scanf("%d", &n);

    // Alocação dinâmica do array
    Item *v = (Item *)malloc(n * sizeof(Item));
    
    // Leitura dos elementos
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Ordenação com mergeSort
    mergeSort(v, 0, n - 1);

    // Impressão dos elementos ordenados
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", v[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(v);

    return 0;
}
