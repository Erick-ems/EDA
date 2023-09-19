#include <stdio.h>

int main() {
  int rod;
  int A, B;
  int countA, countB;
  int rodada = 0;

  int vencedores[100]; 

  while (1) {
    scanf("%d", &rod);

    if (rod == 0) {
      break; 
    }

    int count = 0;
    countA = 0;
    countB = 0;

    while (count != rod) {
      int scanf_result = scanf("%d %d", &A, &B);

      countA += A;
      countB += B;

      count++;
    }

    if (countA > countB) {
      vencedores[rodada] = 1;
    } else {
      vencedores[rodada] = 2;
    }

    rodada++;
  }

  for (int i = 0; i < rodada; i++) {
    if (vencedores[i] == 1) {
      printf("Teste %d\nAldo\n\n", i + 1);
    } else {
      printf("Teste %d\nBeto\n\n", i + 1);
    }
  }

  return 0;
}
