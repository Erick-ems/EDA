#include <stdio.h>



int main(void){

  int n;
  scanf("%d", &n);
  int tamanho = 0;
  int maiorTamanho = 0;

  char p[100];

  for(int i = 0; i < n; i++){
    scanf("%s", p);

    while(p[tamanho] != '\0'){
      tamanho++;
    }
    if(tamanho > maiorTamanho){
      maiorTamanho = tamanho;
    }

  }

  printf("%d\n", tamanho);



  return 0;
}