#include <string.h>

// Função para calcular a "distância" da substring em uma string
int strDist(char* str, char* sub) {

  // Se o comprimento da string for menor que o da substring, retorna 0
  if(strlen(str) < strlen(sub)) 
    return 0;

  // Se a substring for encontrada no início e no final da string
  if(strncmp(str, sub, strlen(sub)) == 0) {
    if(strncmp(str + strlen(str) - strlen(sub), sub, strlen(sub)) == 0) {
      return strlen(str);
    } else {
      // Se a substring não for encontrada no final da string,
      // chama recursivamente a função com a string reduzida em 1 caractere
      return strDist(strndup(str, strlen(str) - 1), sub);
    }
  }

  // Se a substring não for encontrada no início da string,
  // chama recursivamente a função com a string reduzida em 1 caractere
  return strDist(str + 1, sub);
}

int main(){
    char str[101];
    char sub[101];

    // Lê a string e a substring do usuário
    scanf("%s", str);
    scanf("%s", sub);

    // Chama a função strDist e imprime o resultado
    int result = strDist(str, sub);
    printf("%d\n", result);
}
