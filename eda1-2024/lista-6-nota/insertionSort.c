#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t = A; A = B; B = t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertion_sort(Item v[], int l, int r) {
  int elem, i, j;

  // Percorrer array a partir do segundo elemento
  for (i = l + 1; i <= r; i++) {
    elem = v[i]; // Elemento que será (re) inserido

    // Para cada elemento maior
    for (j = i; j > l && elem < v[j-1]; j--) {
      v[j] = v[j-1]; // "Puxar" o maior
    }

    // Inserir o elemento na sua posição
    v[j] = elem;
  }
}

int main() {
  int v[50000];
  int i = 0;

  // Leitura de entrada até o fim do arquivo ou até o limite do array
  while (i < 50000 && scanf("%d", &v[i]) == 1) {
    i++;
  }
  
  int count = i; // Número total de elementos lidos

  insertion_sort(v, 0, count - 1);

  // Impressão dos elementos ordenados
  for (int i = 0; i < count; i++) {
    printf("%d", v[i]);
    if (i < count - 1) {
      printf(" "); // Adiciona espaço entre os números, mas não no final
    }
  }
  printf("\n");

  return 0;
}
