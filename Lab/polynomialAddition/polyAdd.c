#include<stdio.h>
#include<stdlib.h>

#include "polyAdd.h"

int initList(SLL* pl){
    pl->head = NULL;
}

int createList(SLL* pl){

    int choice;
    do{
        NODE* temp = (NODE*)malloc(sizeof(NODE));

        
        printf("enter Power and Coefficient(Ascending Order): ");
        scanf("%d%d",&(temp->pow),&(temp->coeff));

        temp->next = pl->head;
        pl->head = temp;

        printf("do you want to add and Element(1/0)");
        scanf("%d",&choice);
        fflush(stdin);

    }while(choice);
    return 1;
}

void addPoly(SLL* l1, SLL* l2, SLL* sum){
    NODE* p1 = l1->head;
    NODE* p2 = l2->head;

    while (p1!=NULL && p2!=NULL)
    {
        NODE* ele = malloc(sizeof(NODE));
        ele->next = sum->head;
        if(p1->pow > p2->pow)
        {
            ele->coeff = p1->coeff;
            ele->pow = p1->pow;

            p1 = p1->next;
        }
        else if(p1->pow < p2->pow)
        {
            ele->coeff = p2->coeff;
            ele->pow = p2->pow;

            p2 = p2->next;
        }
        else
        {
            ele->coeff = p1->coeff + p2->coeff;
            ele->pow = p1->pow;

            p1 = p1->next;
            p2 = p2->next;
        }
        sum->head = ele;
  
    }

    NODE* temp;
    if(p1 == NULL)
        temp = p2;
    if(p2 == NULL)
        temp = p1;

    while(temp!=NULL)
    {
        NODE* ele = malloc(sizeof(NODE));
        ele->coeff = temp->coeff;
        ele->pow = temp->pow;

        temp = temp->next;
    }
    
}

void disp(SLL* pl){
    if(pl->head == NULL){
        printf("\nEmpty List\n");
        return;
    }
    NODE* temp = pl->head;
    while(temp!=NULL){
        printf("%dx^%d + ",temp->coeff, temp->pow);
        printf("0");
        temp = temp->next;
    }
}
