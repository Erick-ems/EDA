#include <stdio.h>
#include <string.h>

void decodeMessage(unsigned int n, char *buffer, int *index) {
    char decoded[5];  // Armazena a mensagem decodificada
    int i;

    // Decodifica os 4 grupos de 1 byte do número inteiro
    for (i = 0; i < 4; i++) {
        unsigned char byte = (n >> (i * 8)) & 0xFF;
        if (byte == 0) {
            break;  // Fim da mensagem
        }
        decoded[i] = byte;  // Armazena o byte decodificado na mensagem
    }
    decoded[i] = '\0';  // Adiciona o terminador de string
    // Adiciona a mensagem decodificada ao buffer
    strcpy(buffer + *index, decoded);
    // Atualiza o índice do buffer
    *index += strlen(decoded);
}

int main() {
    unsigned int n;
    char buffer[1001];  // Buffer para armazenar a mensagem decodificada
    int index = 0;      // Índice para o buffer
    // Lê os números inteiros em notação hexadecimal até EOF
    while (scanf("%x", &n) != EOF) {
        decodeMessage(n, buffer, &index);
    }
    // Imprime a mensagem decodificada
    printf("%s\n", buffer);
    
    return 0;
}
