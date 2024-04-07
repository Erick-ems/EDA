#include <stdio.h>

int main(void){

    // declarando os possiveis interios
    int n, m, q, pax, pay, pbx, pby;

    // variaveis de uso
    int i = 0;  // Começar com i = 0
    int mova, movb;

    // recebendo o tamanho do quadrado e a posição do professor b
    scanf("%d %d", &n, &m);

    // recebendo a quantidade de contagens
    scanf("%d", &q);

    // associando a posição do professor b
    pbx = n;
    pby = m;

    // associando a posição do professor a
    pax = 1;
    pay = 1;

    // laço de contagem
    while(i < q){

        scanf("%d %d", &mova, &movb);

        if(mova == 1) pay++;
        else if(mova == 2) pay--;
        else if(mova == 3) pax++;
        else if(mova == 4) pax--;

        if(movb == 1) pby++;
        else if(movb == 2) pby--;
        else if(movb == 3) pbx++;
        else if(movb == 4) pbx--;

        if((pax > n) || (pax < 1) || (pay > m) || (pay < 1)) {
            printf("PA saiu na posicao (%d, %d) no passo %d\n", pax, pay, i + 1);
            return 0;  // Termina o programa após a impressão
        }
        else if((pbx > n) || (pbx < 1) || (pby > m) || (pby < 1)) {
            printf("PB saiu na posicao (%d, %d) no passo %d\n", pbx, pby, i + 1);
            return 0;  // Termina o programa após a impressão
        }
        else if((pax == pbx) && (pay == pby)) {
            printf("Encontraram-se na posicao (%d, %d) no passo %d\n", pax, pay, i + 1);
            return 0;  // Termina o programa após a impressão
        }

        i++;

    }

    printf("Nao se encontraram\n");  // Caso nenhum dos casos acima seja verdadeiro

    return 0;

}
