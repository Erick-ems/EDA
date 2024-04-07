#include <stdio.h>

double calculaExpoPos(double n, int e){
    if(e == 0){
        return 1.0;
    } else if(e > 0){
        return n * calculaExpoPos(n, e - 1);
    } else {
        return 1.0 / (n * calculaExpoPos(n, -e - 1));
    }
}

double converteEmPos(double n, int e){
    e = -e;  // Inverte o sinal do expoente
    return calculaExpoPos(n, e);
}

int main(){
    int n;
    int e;
    scanf("%d %d", &n, &e);

    if(n == 0 && e <= 0){
        printf("indefinido\n");
    } else if(e < 0){
        double resultado = converteEmPos(n, e);
        printf("%.*lf\n", -e, 1.0/resultado);  // Imprime o resultado inverso com base no valor de e
    } else {
        double resultado = calculaExpoPos(n, e);
        if (resultado - (int)resultado == 0) {
            printf("%.0lf\n", resultado);  // Imprime o resultado como número inteiro
        } else {
            printf("%.1lf\n", resultado);  // Imprime o resultado com base no valor de e
        }
    }

    return 0;
}
