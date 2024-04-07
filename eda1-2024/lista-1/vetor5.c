#include <stdio.h>


int main(void){

  int quantidade;

  scanf("%d", &quantidade);


  int v[quantidade];

  for(int i = 0; i<quantidade; i++){
    scanf("%d", &v[i]);
  }

  int verifica;

  scanf("%d", &verifica);

  for(int i = 0; i< quantidade; i++){
    if(verifica == v[i]){
      printf("pertence\n");
      break;
    }
    if(i == quantidade -1){
      printf("nao pertence\n");
    }
  }



  return 0;
}