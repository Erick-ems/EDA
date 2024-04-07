#include <stdio.h>

int main(int argc, char **argv) {

  int qtd = argc - 1;

  printf("%d\n", qtd);

  for(int i = 1; i <= qtd; i++) {
    printf("%s\n", argv[i]);
  }

  return 0;
}
