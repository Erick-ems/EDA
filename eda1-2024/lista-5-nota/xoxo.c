#include <stdio.h>
#include <stdlib.h>

void buildSegmentTree(int segTree[], int arr[], int left, int right, int pos) {
    if (left == right) {
        segTree[pos] = arr[left];
        return;
    }
    
    int mid = left + (right - left) / 2;
    buildSegmentTree(segTree, arr, left, mid, 2 * pos + 1);
    buildSegmentTree(segTree, arr, mid + 1, right, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int querySegmentTree(int segTree[], int qLeft, int qRight, int left, int right, int pos) {
    if (qLeft <= left && qRight >= right) {
        return segTree[pos];
    }
    
    if (qLeft > right || qRight < left) {
        return 0;
    }
    
    int mid = left + (right - left) / 2;
    return querySegmentTree(segTree, qLeft, qRight, left, mid, 2 * pos + 1) +
           querySegmentTree(segTree, qLeft, qRight, mid + 1, right, 2 * pos + 2);
}

void updateSegmentTree(int segTree[], int index, int newVal, int left, int right, int pos) {
    if (left == right && left == index) {
        segTree[pos] = newVal;
        return;
    }
    
    if (index < left || index > right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    updateSegmentTree(segTree, index, newVal, left, mid, 2 * pos + 1);
    updateSegmentTree(segTree, index, newVal, mid + 1, right, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *efficiency = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &efficiency[i]);
    }

    int treeSize = 1;
    while (treeSize < N) {
        treeSize *= 2;
    }
    int *segTree = (int *)malloc((2 * treeSize - 1) * sizeof(int));
    buildSegmentTree(segTree, efficiency, 0, N - 1, 0);

    for (int i = 0; i < M; ++i) {
        int type, A, B;
        scanf("%d %d %d", &type, &A, &B);
        if (type == 1) {
            updateSegmentTree(segTree, A - 1, B, 0, N - 1, 0);
        } else {
            printf("%d\n", querySegmentTree(segTree, A - 1, B - 1, 0, N - 1, 0));
        }
    }

    free(efficiency);
    free(segTree);

    return 0;
}
