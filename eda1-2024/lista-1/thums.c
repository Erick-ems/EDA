#include <stdio.h>

int main(void){

  int n;
  int i = 0;

  scanf("%d", &n);

  while(i<n){

    if(i%2 == 0 ){
      printf("THUMS THUMS THUMS \n");
    } else {
      printf("THUMS THUMS THUMS THUMS THUMS THUMS  \n");
    }

    i++;
  }

  return 0;
}