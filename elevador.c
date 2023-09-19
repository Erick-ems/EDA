#include <stdio.h>

//Compiler version gcc  6.3.0

int main()
{
  
  int via, cap, ent, sai, cont = 0;
  
  int contT = 0, exe = 0;
  
  
  scanf("%d %d", &via, &cap);
  
  
  while(cont < via){
    
   scanf("%d %d", &sai, &ent);
    
    
    contT += (ent - sai);
    
    if(contT > cap){
      exe++;
    }
    cont++;
  }
  
  if(exe >= 1){
    
    printf("S\n");
  }else{
    printf("N\n");
  }
  

  return 0;
}