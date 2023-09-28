#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};
int countCellsRecursive(struct Node* head){

    int count = 0;

    if(head == NULL){
        return 0;
    }

    count = countCellsRecursive(head->next) +1;
    free(head);
    
    return count;
}


int main(){

    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;



    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third =(struct Node*)malloc(sizeof(struct Node));


    head->data = 1;
    head->next = second;

    second->data = 2;
    head->next = third;

    third->data = 3;
    head-> next = NULL;

    int count = countCellsRecursive(head);

    printf("numero de celulas de forma recursiva %d\n", countCellsRecursive);



    return 0;
}