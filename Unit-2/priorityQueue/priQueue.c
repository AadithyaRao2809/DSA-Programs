#include <stdio.h>
#include <stdlib.h>

#include "priQueue.h"


void init(QUEUE* n)
{
    n->head=NULL;
}

void enQueue(QUEUE* header, NODE* element)
{
    if(header->head==NULL)
    {
        header->head=element;
        element->next=NULL;
    }
    else if((header->head->pri)<(element->pri))
    {
        NODE* prev = header->head;
        header->head = element;
        element->next = prev;
        prev=NULL;
    }
    else
    {
        NODE* current = header->head->next;
        NODE* prev = header->head;

        while(current!=NULL && current->pri > element->pri)
        {
            prev=current;
            current=current->next;
        }

        prev->next=element;
        element->next=current;

        current=NULL;
        prev=NULL;
    }
    element=NULL;    
}

int deQueue(QUEUE* header, NODE* ele)
{
    if(header->head == NULL)
        return 0;
    *ele = *(header->head);
    ele->next = NULL;

    NODE* temp = header->head;
    header->head = header->head->next;
    free(temp);
    return 1;

}

void disp(QUEUE* n)
{
    NODE* m = n->head;

    if(m == NULL)
        printf("Empty Queue\n");

    printf("\nDisplaying Elements\n");

    while(m!=NULL)
    {
        printf("%d(%d)\n",m->info, m->pri);
        m=m->next;
    }
}

int isEmpty(QUEUE* p)
{
    if(p->head == NULL)
        return 1;
    return 0;
}





