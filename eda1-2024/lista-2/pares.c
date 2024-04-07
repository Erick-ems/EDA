#include <stdio.h>

int contaPares(char str[], int i){
  if(str[i] == '\0' || str[i + 1] == '\0'){
    return 0;
  }
  if(str[i] == str[i + 2]){
    return 1 + contaPares(str, i + 1);
  }else{
    return contaPares(str, i + 1);
  }
}

int main(){
  char str[201];
  scanf("%s", str);

  int qtdPares = contaPares(str, 0);

  printf("%d\n", qtdPares);


  return 0;
}