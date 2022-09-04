#include<stdio.h>
#include<stdlib.h>

#include "doubly.h"

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
    printf("Enter element to add");
    scanf("%d",temp->info);
    do
    {
        NODE* temp = malloc(sizeof(NODE));
        temp->next = p->head;
        p->head = temp;
        temp->prev = NULL;

        printf("Enter element to add");
        scanf("%d",temp->info);

        printf("Contine? ");
        scanf("%d",cont);
    } while (cont);
    
}
void insertNode(DLL* p, int n)
{
    if(p->head == NULL)
    {
        NODE* temp = malloc(sizeof(NODE));

        p->head = temp;
        temp->next = NULL;
        temp->prev = NULL;
        
        printf("Enter element to add");
        scanf("%d",temp->info);

        return;
    }
    

    NODE* temp = malloc(sizeof(NODE));
    NODE* cur = p->head;

    for(int i=0; i<n-1 && cur->next!=NULL; i++)
        cur = cur->next;

    temp->next  = cur->next;
    temp->prev = cur;
    cur->next = temp;
    temp->next->prev = temp;
    
    printf("Enter element to add");
    scanf("%d",temp->info);




}
int deleteNode(DLL* p, int n)
{
    if(p->head == NULL)
        return 0;
    
    NODE* temp = p->head;
    for(int i=0; i<n-1 && temp->next!=NULL; i++)
        temp = temp->next;
    
    NODE* del = temp->next;
    
    temp->next = del->next;
    del->next->prev = temp;

    free(del);
}
void dispList(DLL* p)
{
    NODE* temp = p->head;
    while(temp!=NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}