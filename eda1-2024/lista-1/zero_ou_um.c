#include <stdio.h>

int empate(int a, int b, int c){
  if(a == b && a == c && b == c)
    return 1;
  return 0;
}

int aGanha(int a, int b, int c){
  if(a != b && a != c && b == c)
    return 1;
  return 0;
}

int bGanha(int a, int b, int c){
  if(b != c && b != a && a == c)
    return 1;
  return 0;
}

int cGanha(int a, int b, int c){
  if(c != a && c != b && b == a)
    return 1;
  return 0;
}

int main (void){
  int num1, num2, num3;

  scanf("%d %d %d", &num1, &num2, &num3);

  if(empate(num1, num2, num3))
    printf("Empate\n");
  else if(aGanha(num1, num2, num3))
    printf("A\n");
  else if(bGanha(num1, num2, num3))
    printf("B\n");
  else if(cGanha(num1, num2, num3))
    printf("C\n");

  return 0;
}
