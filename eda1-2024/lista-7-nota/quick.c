#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int partition(int *v, int l, int r) {
    int pivot = v[r];
    int i = l - 1, j = r;
    while (i < j) {
        while (v[++i] < pivot);
        while (v[--j] > pivot && j > l);
        if (i < j) exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quick_sort(int *v, int l, int r) {
    if (r <= l) return;
    int p = partition(v, l, r);
    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

int main() {
    int n;

    scanf("%d", &n);

    Item arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
