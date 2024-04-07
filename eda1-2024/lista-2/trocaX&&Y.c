#include <stdio.h>
#include <string.h>


void trocaXandY(char *str, int start, int end){
  if(start >= end){
    return;
  }

  if(str[start] == 'x'){
    str[start] = 'y';
    trocaXandY(str, start + 1, end);
  }else {
    trocaXandY(str, start + 1, end);
  }
}

int main(){
  char str[80];

  scanf("%s", str);

  int len = strlen(str);

  trocaXandY(str, 0, len);

  printf("%s\n", str);

  return 0;
}