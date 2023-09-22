// vou fazer um lista iterativa com base no documento do manual e depois comparar com a que o chat fez

#include <stdio.h>
#include <stdlib.h>


// uma variavel do tipo struct  com o nome de NODE
struct Node{
    int data; // Armazena a parte inteiro da celula
    struct Node* next: // crio um ponteiro que vai apontar para a proxima posição
    // ele contem o nome node porque ele vai apontar para outra celula, da mesma caracteristica de NODE, através do ponteiro NEXT
}

// aqui eu vou criar um contador de forma iterativa
// que vai passar os parametros da struct criada 
// e cada struct aponta para um proximo
// aqui nessa função o nosso proximo vai ser a cabeça de outra celula
int countCellsIterative(struct Node* head){
    int count = 0;
    struct Node* current = head; //nois chama a struct um ponterio passamos valor atual sendo a cabeça da celula


    // enquanto o atual nao for o ultimo elemento da lista que é o NULL
    while(current != NULL){
        count++; //fazer um contador de repetições o que da na mesma da celulas
        struct Node* temp = current; // nos vamos criar uma váriavel que armazenar temporariamnete a celula atual, pois o objetivo é só contar
        current = current->next; // agora currente passa para a poxima posição, que será a cabeça
        free(temp);// liberamos a memoria da váriavel
        // volta pro inicio e verifica se a posição do current é null ou não
    }

}



















int main(){





    return 0;
}