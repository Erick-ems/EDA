#include <stdio.h>

int main() {
    int limite, numero, soma = 0;

    // Leitura do limite de soma
    scanf("%d", &limite);

    while (1) {
        scanf("%d", &numero);

        // Se o número lido for zero, encerramos a entrada de dados
        if (numero == 0) {
            break;
        }

        soma += numero;

        // Se a soma ultrapassar o limite, imprimimos o número atual
        if (soma > limite) {
            printf("%d\n", numero);
            soma = numero;  // Reiniciamos a soma para o próximo grupo de números
        }
    }

    return 0;
}
