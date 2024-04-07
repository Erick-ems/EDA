#include <stdio.h>

// Funções para calcular o multiplicador de nível baseado no tipo e nível
double fogo(int nivel) {
    if (nivel == 1)  return 2.0;
    else if (nivel == 2) return 3.0;
    else if (nivel == 3) return 5.0;
}

double agua(int nivel) {
    if (nivel == 1)  return 1.0;
    else if (nivel == 2) return 2.5;
    else if (nivel == 3) return 4.0;
}

double terra(int nivel) {
    if (nivel == 1)  return 2.5;
    else if (nivel == 2) return 5.5;
    else if (nivel == 3) return 7.0;
}

double tipoEquipe(int tipoPlayer, int nivelPlayer) {
    if (tipoPlayer == 1) return terra(nivelPlayer);
    if (tipoPlayer == 2) return fogo(nivelPlayer);
    if (tipoPlayer == 3) return agua(nivelPlayer);
}

double calculaVantagem(int tipoPlayer, int tipoCPU) {
    if (tipoPlayer == 2) {
        if (tipoCPU == 1) return 1.0;
        if (tipoCPU == 2) return 0.5;
        if (tipoCPU == 3) return 2.0;
    }
    if (tipoPlayer == 3) {
        if (tipoCPU == 1) return 2.0;
        if (tipoCPU == 2) return 1.0;
        if (tipoCPU == 3) return 0.5;
    }
    if (tipoPlayer == 1) {
        if (tipoCPU == 1) return 0.5;
        if (tipoCPU == 2) return 2.0;
        if (tipoCPU == 3) return 1.0;
    }
    return 1.0;
}

double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU) {
    double multTipo = calculaVantagem(tipoPlayer, tipoCPU);
    double multNivel = tipoEquipe(tipoPlayer, nivelPlayer);
    double dano = 100 * multTipo * multNivel - defesaCPU;
    
    if (dano < 0) {
        dano = 0;
    }
    return dano;
}

int main() {
    int tipoPlayer, nivelPlayer, tipoCPU;
    double defesaCPU;

    printf("Digite o tipo do jogador (1 para terra, 2 para fogo, 3 para agua): ");
    scanf("%d", &tipoPlayer);

    printf("Digite o nivel do jogador: ");
    scanf("%d", &nivelPlayer);

    printf("Digite o tipo da CPU (1 para terra, 2 para fogo, 3 para agua): ");
    scanf("%d", &tipoCPU);

    printf("Digite a defesa da CPU: ");
    scanf("%lf", &defesaCPU);

    double dano = calculaDano(tipoPlayer, nivelPlayer, tipoCPU, defesaCPU);

    printf("O dano calculado é: %.2lf\n", dano); // Ajustado para imprimir com duas casas decimais

    return 0;
}
