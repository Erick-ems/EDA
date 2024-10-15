#include <stdio.h>

int main(int argc, char **argv) {

  int qtd = argc - 1; //associação é constante O(1)

  printf("%d\n", qtd);

  for(int i = 1; i <= qtd; i++) {//percorre o vetor uma vez O(N)
    printf("%s\n", argv[i]);
  }

  return 0;
}
//Complexidade O(N)