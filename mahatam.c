 

#include <stdio.h>
#include <stdlib.h>
//Compiler version gcc  6.3.0

int main()
{
  
  int a,b,c,d, e;
  scanf("%d %d %d %d", &a,&b,&c,&d);
  
 e = abs(a-c)+ abs(b-d);


  printf("%d\n", e);
  
  
  return 0;
}
