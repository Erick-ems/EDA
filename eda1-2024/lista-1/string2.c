#include <stdio.h>
#include <string.h>

int main(){

  char c[1000];
  scanf("%s", c);

  int tamanho = 0;

  while(c[tamanho] != '\0'){
    tamanho++;
  }

  for(int i = tamanho - 1; i >= 0 ; i--){
    printf("%c", c[i]);
  }
  printf("\n");

  return 0;
}