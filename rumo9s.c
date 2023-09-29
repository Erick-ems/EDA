#include <stdio.h>
#include <string.h>

int main() {
    char num[1001]; // Armazena o número como uma string
    int degree = 0; // Inicializa o grau-9 como 0
    int v[100]; // Vetor para armazenar valores 1 ou 0

    while (1) {
        scanf("%s", num);

        if (num[0] == '0') {
            break; // Fim da entrada
        }

        int len = strlen(num);
        int sum = 0;

        // Calcula a soma dos dígitos
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }

        // Verifica se a soma é um múltiplo de nove
        if (sum % 9 == 0) {
            v[degree] = 1; // Armazena 1 no vetor v
            degree = 1;

            // Calcula o grau-9
            while (sum != 9) {
                int new_sum = 0;

                while (sum > 0) {
                    new_sum += sum % 10;
                    sum /= 10;
                }

                sum = new_sum;
                degree++;
            }
        } else {
            v[degree] = 0; // Armazena 0 no vetor v
        }
    }

        for(int i = 0; i < degree; i++) {
            if(v[i] == 1){
                printf("is a multiple of 9 and has 9-degree %d.\n", degree);
            } else {
                printf("is not a multiple of 9.\n");
        }
    }

    return 0;
}
