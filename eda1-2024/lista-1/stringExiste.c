#include <stdio.h>



int main(void){

  int m, n;
  scanf("%d%d", &m, &n);
  char *p[m];
  char *l[n];
  int contem = 0;

  for(int i = 0; i < m; i++){
    scanf("%s", &p[i]);
  }

  for(int i = 0; i < n; i++){
    scanf("%s", &l[i]);
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(l[j] == p[i]){
        contem++;
        printf("1\n");
        break;
      }
    }
  }
  if(contem = 0){
    printf("0\n");
  }


  return 0;
}