#include <stdio.h>

#define MAX_SIZE 500

int main(void){

  int fileiras, lugares;

  while(scanf("%d%d", &fileiras, &lugares) != EOF){

    char fila[fileiras];
    int lugar[fileiras][lugares]; // Crie uma matriz para armazenar os lugares em cada fileira

    // Inicialize a matriz lugar com zeros
    for(int i = 0; i < fileiras; i++){
      for(int j = 0; j < lugares; j++){
        lugar[i][j] = 0;
      }
    }

    char c;
    int n;
    while(scanf(" %c%d", &c, &n) == 2){
      fila[c - 'A'] = c;
      lugar[c - 'A'][n - 1] = 1; // Marque o lugar como ocupado
    }

    // Imprima os números
    printf("  ");
    for(int i = 1; i <= lugares; i++){
      printf("%02d ", i);
    }
    printf("\n");

    // Imprima as fileiras e lugares
    for(int i = fileiras - 1; i >= 0; i--){
      printf("%c ", fila[i]);
      for(int j = 0; j < lugares; j++){
        if(lugar[i][j] == 1){ // Verifique se o lugar j na fileira i está ocupado
          printf("XX ");
        }else{
          printf("-- ");
        }
      }
      printf("\n");
    }
  }

  return 0;

}
