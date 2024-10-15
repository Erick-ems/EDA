#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 0; // Retorna 0 indicando falha na inserção
    }
    nova_celula->dado = x; // Insere o elemento x na nova célula
    nova_celula->prox = p->prox; // A nova célula aponta para o elemento anterior do topo
    p->prox = nova_celula; // Atualiza o topo da pilha para a nova célula
    return 1; // Retorna 1 indicando sucesso na inserção
}
