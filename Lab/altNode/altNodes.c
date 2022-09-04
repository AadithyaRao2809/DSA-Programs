#include<stdio.h>
#include<stdlib.h>

#include "altNodes.h"

int initList(SLL* pl){
    pl->head = NULL;
}

int createList(SLL* pl){

    int choice;
    do{
        NODE* temp = (NODE*)malloc(sizeof(NODE));

        
        printf("Enter Number: ");
        scanf("%d",&(temp->info));

        temp->next = pl->head;
        pl->head = temp;

        printf("Do you want to add and Element(y/n)");
        scanf("%d",&choice);
  
    }while(choice);
    return 1;
}

void disp(SLL* pl){
    if(pl->head == NULL){
        printf("\nEmpty List\n");
        return;
    }
    NODE* temp = pl->head;
    while(temp!=NULL){
        printf("%d ",temp->info);
        printf("0");
        temp = temp->next;
    }
}

void delNode(SLL* pl){
    if(pl->head == NULL)
        return;
    
    NODE* del = pl->head->next;
    NODE* prev = pl->head;

    prev->next = del->next;
    free(del);

    while(prev->next != NULL && prev->next->next != NULL)
    {
        prev = prev->next;
        del = prev->next;

        prev->next = del->next;
        free(del);
    }
}

