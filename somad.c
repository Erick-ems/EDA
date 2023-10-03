#include <stdio.h>




unsigned long long soma(unsigned long long n) {
    if (n == 0) {
        return 0;
    } else {
        unsigned long long digito = n % 10;
        return digito + soma(n / 10);
    }
}





int main(){


    unsigned long long n;
    
    scanf("%llu", &n);


    printf("%llu\n", soma(n));
    return 0;
}