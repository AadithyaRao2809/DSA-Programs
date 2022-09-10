#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void init(STACK* p)
{
    p->top = NULL;
}

int isEmpty(STACK* p)
{
    if(p->top == NULL)
        return 1;
    return 0;
}

int peep(STACK* p, int* n)
{
    if(isEmpty(p))
        return 0;
    *n = p->top->info;
    return 1;
}

void push(STACK* p, int n)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = n;
    temp->next = p->top;
    p->top = temp;
}

int pop(STACK* p, int* n)
{
    peep(p,n);

    if(isEmpty(p))
        return 0;

    NODE* temp = p->top;
    p->top = p->top->next;
    free(temp);

    return 1;
}