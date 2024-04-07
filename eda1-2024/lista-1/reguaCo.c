#include <stdio.h>

void drawRuler(int n, int h) {
    if (n == 0) return;
    drawRuler(n-1, h-1);
    for (int i = 0; i < h; i++) printf("-");
    printf("\n");
    drawRuler(n-1, h-1);
}

int main() {
    int n;
    scanf("%d", &n);
    drawRuler(n, n);
    return 0;
}