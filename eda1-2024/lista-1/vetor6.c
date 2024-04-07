#include <stdio.h>


int main(void){

  int quantidade;
  scanf("%d", &quantidade);

  int v[quantidade];
  int k[quantidade];
  int r[quantidade];


  for(int i = 0; i < quantidade; i++){
    scanf("%d", &v[i]);
  }
  for(int i = 0; i < quantidade; i++){
    scanf("%d", &k[i]);
  }
  for(int i = 0; i < quantidade; i++){
    r[i] = v[i] + k[i];
  }

  for(int i = 0; i < quantidade; i++){
    printf("%d ", r[i]);
  }
  printf("\n");


  return 0;
}