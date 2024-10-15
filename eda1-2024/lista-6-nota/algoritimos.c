#include <stdio.h>

#define exch(A,B) {int t = A, A = B, B = t}

void selectionSort(int v[], int l, int r){
  //ele começa no primeiro elemento
  int menor;
  for(int i = l; i < r; i++){
    menor = i;

    for(int j = i+1; j <= r; j++){
      if(v[j] < v[menor]){
        menor = j;
      }
    }
    if(i != menor){
      exch(v[i], v[menor]);
    }
  }
  //complexidade = n^2
  //adaptativo = nao
  //estavel = nao
  //in place = sim
}

void bubbleSort(int v[], int l, int r){
  //procura o maior elemento 
  //se ele encontra ele troca
  //leva esse ultimo elemento ate o topo
  // decrementa o topo

  for(; r < l; r--){
    for(int j = l; j < r; j++){
      if(v[j] > v[j + 1]){
        exch(v[j], v[j+1])
      }
    }
  }

  //complexidade = N²
  //adaptativo = nao
  //estavel = sim
  //in place = sim
}

void insertionSort(int v[], int l, int r){
  for(int i = l+1; i <= r; i++){
    for(int j = i; j > l; j--){
      if(v[j] < v[j-1]){
        exch(v[j], v[j-1])
      }
    }
  }
}


void merge(int *v, int l, int m, int r){
  int *v2 = malloc(sizeof(Item)(r - l +1));
  int k = 0;
  int i = l;
  int j = m + 1;

  while(i<=l && j<= r){
    if(v[i] < v[j]){
      v2[k++] = v[i++];
    }else{
      v2[i] = v[j++];
    }
  }
  for(int i = 0; i < r; i++){
    v[i] = v2[i];
  }
  free(v2);
}

mergesort(int v[], int l, int r){
  if(l <= r) return;
  int m = (r + l)/2;
  mergesort(v, l, m);
  mergesort(v, m + 1, r);
  merge(v, l, m, r); 
}