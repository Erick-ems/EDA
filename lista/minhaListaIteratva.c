// vou fazer um lista iterativa com base no documento do manual e depois comparar com a que o chat fez

#include <stdio.h>
#include <stdlib.h>


// uma variavel do tipo struct  com o nome de NODE
struct Node{
    int data; // Armazena a parte inteiro da celula
    struct Node* next; // crio um ponteiro que vai apontar para a proxima posição
    // ele contem o nome node porque ele vai apontar para outra celula, da mesma caracteristica de NODE, através do ponteiro NEXT
};

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


    return count;

}

int main(){


    // criamos 3 celulas para serem contadas
    // todas definidas como nulo, pois depois irão receber o valor
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;



    // aqui alocamos memoria para essa cada celula
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // aqui atribuimos o valor e apotamos o endereço da proxima celula
    head->data = 1;
    head->next = second;

    head->data = 2;
    head->next = third;

    head->data = 3;
    head->next = NULL;

    // chamamos o contador das celulas dada a cabeça como parametro
    int count = countCellsIterative(head);
    printf("numero de celulas da coluna %d\n", countCellsIterative);

    free(head);
    free(second);
    free(third);






    return 0;
}