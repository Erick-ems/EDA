#include <stdio.h>



long int fibonacci (int n){

    if(n == 0) return 0;
    if(n < 3) return 1;   
    else return fibonacci(n-1) + fibonacci(n-2);

}