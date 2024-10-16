#include <stdio.h>

long int fib_cache[81];

long int fibonacci (int n){
  if(n <= 1 ) return n;

  if(fib_cache[n] != 0){
    return fib_cache[n];
  }

  fib_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);

  return fib_cache[n];
}

int main() {
  int n;
  printf("Digite um número: ");
  scanf("%d", &n);
  printf("Fibonacci de %d = %ld\n", n, fibonacci(n));
  return 0;
}