#include <stdlib.h>

// Declaração da estrutura da fila
typedef struct fila {
    int *dados; // Vetor de dados da fila
    int N;      // Capacidade máxima da fila
    int p;      // Índice do primeiro elemento
    int u;      // Índice do próximo espaço livre
} fila;

// Função para redimensionar a fila, se necessário
void redimensionaFila(fila *f) {
    int novoTamanho = f->N * 2; // Dobrar o tamanho da fila
    int *novosDados = (int *)malloc(novoTamanho * sizeof(int)); // Alocar novo vetor
    int i;
    // Copiar os elementos da fila antiga para a nova fila
    for (i = 0; i < f->N; i++)
        novosDados[i] = f->dados[i];
    free(f->dados); // Liberar memória do vetor antigo
    // Atualizar ponteiros e capacidade da fila
    f->dados = novosDados;
    f->N = novoTamanho;
}

// Função para enfileirar um elemento na fila
int enfileira(fila *f, int x) {
    // Verificar se há espaço na fila
    if (f->u == f->N) {
        redimensionaFila(f); // Redimensionar a fila se necessário
    }
    // Inserir o elemento na próxima posição livre
    f->dados[f->u] = x;
    f->u++; // Atualizar o índice do próximo espaço livre
    return 1; // Retornar 1 para indicar que a inserção foi bem-sucedida
}
