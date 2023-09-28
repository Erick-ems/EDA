#include <stdio.h>
#include <stdlib.h> // Include for malloc and free



int f91(int N) {
    if (N <= 100) {
        // Caso base: retorna 91 de acordo com a definição do problema
        return f91(f91(N + 11));
    } else {
        // Quando N >= 101, retorna N - 10 de acordo com a definição do problema
        return N - 10;
    }
}



int main() {
    int N;
    int cont = 0;

    scanf("%d", &N);

    int* v = (int*)malloc(N * sizeof(int)); // Allocate memory for the array


    while (1) {
        if (N == 0) {
            break;
        }

        v[cont] = N;
        int M;

        M = f91(N);
        // Calculate f91(N) and store it in the array
        v[cont + 1] = M;

        cont += 2; // Increment by 2 to store both N and M

        scanf("%d", &N);
    }

    for (int i = 0; i < cont; i += 2) {
        printf("f91(%d) = %d\n", v[i], v[i + 1]);
    }

    // Free the dynamically allocated memory
    free(v);

    return 0;
}
