#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t = A; A = B; B = t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void selectionSort(Item *v, int l, int r) {
  for (int i = l; i < r; i++) {
    int min = i;
    for (int j = i + 1; j <= r; j++) {
      if (less(v[j], v[min])) {
        min = j;
      }
    }
    exch(v[i], v[min]);
  }
}

int main() {
  int v[1000];
  int i = 0;
  int count = 0;

  while (scanf("%d", &v[i]) != EOF) {
    i++;
  }
  count = i;

  selectionSort(v, 0, count - 1);

  for (int i = 0; i < count; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
