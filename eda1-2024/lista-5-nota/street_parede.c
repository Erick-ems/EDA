#include <stdio.h>

// Função para verificar se os caminhões podem ser reordenados de acordo com a ordem desejada
char* can_reorder_love_mobiles(int n, int order[]) {
    int stack[1001]; // Pilha para armazenar os caminhões temporariamente
    int top = -1; // Índice do topo da pilha
    int expected = 1; // Próximo caminhão esperado na ordem

    // Iterar sobre os caminhões na ordem de chegada
    for (int i = 0; i < n; i++) {
        // Se o caminhão atual é o próximo esperado na ordem, apenas atualize o próximo esperado
        if (order[i] == expected) {
            expected++;
        }
        // Se o caminhão atual é o próximo esperado na pilha, desempilhe até que não seja mais
        while (top >= 0 && stack[top] == expected) {
            top--;
            expected++;
        }
        // Se o caminhão atual não é o próximo esperado, empilhe-o
        else {
            stack[++top] = order[i];
        }
    }

    // Se todos os caminhões foram processados corretamente, a reordenação é possível
    return (top == -1) ? "yes" : "no";
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int order[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &order[i]);
        }
        printf("%s\n", can_reorder_love_mobiles(n, order));
    }
    return 0;
}
