#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A=B; B=t;}
#define cmpexch(A,B) if(less(A,B)) exch(A,B)

void selectionSort(int v[], int l, int r){
  int menor;
  for(int i = l; i < r; i++){
    menor = i; // Initialize 'menor' to the current index
    for(int j = i+1; j <= r; j++){
      if(less(v[j], v[menor])) menor = j;
    }
    if(i != menor) exch(v[i], v[menor]);
  }
}

int main(){
  int array[1000];
  int n = 0; // Initialize n to 0

  // Correct the while loop condition
  while(scanf("%d", &array[n]) != EOF){
    n++;
  }

  selectionSort(array, 0, n-1); // Correct function name to selectionSort
  for(int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }

  printf("\n");
  return 0;
}
