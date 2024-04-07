#include <stdio.h>

int main(void){

  int quantidade;

  scanf("%d", &quantidade);

  int v[quantidade];
  int par[quantidade];
  int impar[quantidade];

  int countPar = 0;
  int countImpar = 0;

  for(int i = 0; i < quantidade; i++){
    scanf("%d", &v[i]);
    if(v[i] % 2 == 0){
      par[countPar] = v[i];
      countPar++;
    }else{
      impar[countImpar] = v[i];
      countImpar++;
    }
  }

  for(int i = 0; i < countPar; i++){
    printf("%d ", par[i]);
  }
  printf("\n");
  for(int i = 0; i < countImpar; i++){
    printf("%d ", impar[i]);
  }
  printf("\n");

  return 0;
}