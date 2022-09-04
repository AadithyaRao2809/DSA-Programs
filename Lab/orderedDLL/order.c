#include<stdio.h>
#include<stdlib.h>

#include "order.h"

void init(DLL* p)
{
    p->head = NULL;
}

void createList(DLL* p)
{
    int cont;
    NODE* temp = malloc(sizeof(NODE));
    p->head = temp;
    temp->next = NULL;
    temp->prev = NULL;
    do
    {
        int n;
        printf("Enter element to add");
        scanf("%d",&n);

        insertNode(p,n);

        printf("Continue? ");
        scanf("%d",&cont);
    } while (cont);
    
}


void insertNode(DLL* p, int n)
{   
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = n;

    if(p->head == NULL)
    {
        p->head = temp;
        temp->next = NULL;
        temp->prev = NULL;

        return;
    }
    NODE* cur = p->head;
    
    if(temp->info < cur->info)
    {
        p->head = temp;
        temp->next = cur;
        cur->prev = temp;
        temp->prev = NULL;

        return;

    }
    while(temp->info > cur->info && cur->next != NULL)
        cur = cur->next;

    if(cur->next != NULL)
    {
        temp->next = cur;
        cur->prev->next = temp;
        temp->prev = cur->prev;
        cur->prev = temp;
        
        return;
    }

    if(temp->info < cur->info)
    {
        temp->prev = cur->prev;
        temp->next = cur;
        cur->prev->next = temp;
        cur->prev = temp;

        return;
    }  
    cur->next = temp;
    temp->prev = cur;
    temp->next = NULL;
    
}



void dispList(DLL* p)
{
    NODE* temp = p->head;
    while(temp->next!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}