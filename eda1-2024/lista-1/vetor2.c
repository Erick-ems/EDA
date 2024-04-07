#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);

  int v[n];

  int *ptr = v;  // ponteiro para o primeiro elemento do array
  int menor = *ptr;
  int posicao = 0;

  for(int i = 0; i < n; i++){
    scanf("%d", ptr);
    if(*ptr < menor){
      menor = *ptr;
      posicao = i;
    }
    ptr++;  // avança o ponteiro para o próximo elemento
  }

  printf("%d\n", posicao);

  return 0;
}
