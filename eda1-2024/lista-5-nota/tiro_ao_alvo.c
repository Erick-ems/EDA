#include <stdio.h>

int main() {
    int C, T;
    scanf("%d %d", &C, &T);

    int raios[C];
    for (int i = 0; i < C; i++) {
        scanf("%d", &raios[i]);
    }

    int pontos = 0;
    for (int i = 0; i < T; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);

        for (int j = 0; j < C; j++) {
            if (X*X + Y*Y <= raios[j]*raios[j]) {
                pontos += C - j;
                break;
            }
        }
    }

    printf("%d\n", pontos);

    return 0;
}
