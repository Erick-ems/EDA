#include <stdio.h>


int main(){


    int m, i;
    int teste = 1;
    int lista[100];


    while(1){

        scanf("%d", &m);


        if(m == 0){
            break;
        }



        char operador;
        int resultado = 0;
        int operando;


        scanf("%d", &operando);
        resultado = operando;


        for(int i = 1; i < m; i++){
            scanf(" %c%d", &operador, &operando);

            if(operador == '+'){
                resultado += operando;
            }else if(operador == '-'){
                resultado -= operando;
            }
        }


        lista[teste-1] = resultado;




        teste++;
    }
    
    int j = 1;

    for(int i = 0; i < teste - 1; i++){
        printf("Teste %d\n", j++);
        printf("%d\n\n", lista[i]);
    }






    return 0;
}