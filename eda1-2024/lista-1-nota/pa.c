#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    if (primeiro >= ultimo) {
        return 1;
    }

    // Verifica se a condição da progressão aritmética é satisfeita
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1]) {
        return 0; // A sequência não é uma progressão aritmética
    }

    // Chama recursivamente com os próximos elementos
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}
