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
    int i, j;
    // Copiar os elementos da fila antiga para a nova fila
    for (i = 0, j = f->p; j != f->u; i++, j = (j + 1) % f->N)
        novosDados[i] = f->dados[j];
    free(f->dados); // Liberar memória do vetor antigo
    // Atualizar ponteiros e capacidade da fila
    f->dados = novosDados;
    f->p = 0;
    f->u = i;
    f->N = novoTamanho;
}

// Função para enfileirar um elemento na fila
int enfileira(fila *f, int x) {
    // Verificar se a fila está cheia
    if ((f->u + 1) % f->N == f->p) {
        redimensionaFila(f); // Redimensionar a fila se necessário
    } 
    
    // Verificar novamente se a fila está cheia após a possível redimensionamento
    if ((f->u + 1) % f->N == f->p) {
        return 0; // Retornar 0 para indicar que a inserção falhou devido à fila estar cheia
    }
    
    // Inserir o elemento na posição do próximo espaço livre
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N; // Atualizar o índice do próximo espaço livre
    return 1; // Retornar 1 para indicar que a inserção foi bem-sucedida
}
