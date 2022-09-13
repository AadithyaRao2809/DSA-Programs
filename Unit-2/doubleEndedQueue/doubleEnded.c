#include<stdio.h>
#include<stdlib.h>

#include "doubleEnded.h"

void init(QUEUE* p)
{
    p->head = NULL;
    p->tail = NULL;
}

void insertRear(QUEUE* p, int n)
{
    NODE* ele = (NODE*)malloc(sizeof(NODE));
    ele->info = n;

    if(p->head == NULL)
    {
        p->head = ele;
        p->tail = ele;
        return;
    }
    ele->next = NULL;
    ele->prev = p->tail;
    p->tail->next = ele;

}

void insertFront(QUEUE* p, int n)
{
    NODE* ele = (NODE*)malloc(sizeof(NODE));
    ele->info = n;

    if(p->head == NULL)
    {
        p->head = ele;
        p->tail = ele;
        return;
    }
    ele->prev = NULL;
    ele->next = p->head;
    p->head = ele;

}

int deleteFront(QUEUE* p, int* n)
{
    if(p->head == NULL)
        return 0;
    *n = p->head->info;

    if(p->head->next == NULL)
    {
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
    }

    p->head = p->head->next;
    free(p->head->prev);
}

int deleteRear(QUEUE* p, int* n)
{
    if(p->head == NULL)
        return 0;
    *n = p->tail->info;

    if(p->tail->prev == NULL)
    {
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
    }

    p->tail = p->tail->prev;
    free(p->tail->next);
    
}

void disp(QUEUE* p)
{
    NODE* temp = p->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp = temp->next;
    }
}