#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A,B) { Item t = A; A = B; B = t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubblesort(Item *v, int l, int r) {
  for (int i = l; i < r; i++) {
    for (int j = l + 1; j <= r; j++) {
      cmpexch(v[j-1], v[j]);
    }
  }
}

int main() {
  int v[1000];
  int i = 0;
  int count = 0;

  while (scanf("%d", &v[i]) != EOF) {
    i++;
    count++;
  }

  bubblesort(v, 0, count - 1);

  for (int i = 0; i < count; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
