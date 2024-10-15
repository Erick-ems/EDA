#include <stdio.h>



int buscaBinaria(int v[], int n, int x){
  int low = 0, high = n;
  while(low<high){
    int mid = (low + high) / 2;
    if(v[mid] < x){
      low = mid + 1;
    }else{
      high = mid;
    }
  }
  return low;
}

int main(){
  int N,M;

  scanf("%d%d", &N, &M);

  int V[N];
  int buscas[M];

  for(int i = 0; i < N; i++){
    scanf("%d", &V[i]);
  }

    for(int i = 0; i < M; i++){
    scanf("%d", &buscas[i]);
  }

  for(int i = 0; i < M; i++){
    int resultado = buscaBinaria(V, N, buscas[i]);
    printf("%d\n", resultado);
  }


}