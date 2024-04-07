#include <stdio.h>

int main(void){

  int n,m;
  scanf("%d%d", &n,&m);

  int matriz[n][m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d",&matriz[i][j]);
    }
  }

  int somaLinha[n];
  int maiorNumeroLinha = 0;
  int maiorNumeroColuna = 0;

  for(int i = 0; i < n; i++){
    somaLinha[i] = 0;
    for(int j = 0; j < m; j++){
      somaLinha[i] += matriz[i][j];
    }
    if(somaLinha[i] > maiorNumeroLinha){
      maiorNumeroLinha = somaLinha[i];
    }
  }

  int somaColuna[m];

  for(int i = 0; i < m; i++){
    somaColuna[i] = 0;
    for(int j = 0; j < n; j++){
      somaColuna[i] += matriz[j][i];
    }
    if(somaColuna[i] > maiorNumeroColuna){
      maiorNumeroColuna = somaColuna[i];
    }
  }

  int maiorNumero;

  if(maiorNumeroColuna > maiorNumeroLinha){
    maiorNumero = maiorNumeroColuna;
  }else{
    maiorNumero = maiorNumeroLinha;
  }

  printf("%d\n", maiorNumero);

  return 0;
}