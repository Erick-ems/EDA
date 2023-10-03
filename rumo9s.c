#include <stdio.h>

unsigned long long mult9(unsigned long long soma, int cont){
    if(soma % 9 != 0 ){
        return printf("%llu is a multiple of 9 and has 9-degree %d",soma, cont);
    }else{
        return printf("%llu is not a multiple of 9 and has 9-degree %d",soma, cont);
    }


}

unsigned long long soma(unsigned long long n) {
    int cont = 0;
    if (n == 0) {
        return mult9(soma, cont);
    } else {
        unsigned long long digito = n % 10;
        cont++;
        return digito + soma(n / 10);
    }
}





int main(){


    unsigned long long n;
    
    scanf("%llu", &n);
    soma(n);

    mult9();
    return 0;
}