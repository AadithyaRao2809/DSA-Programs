#include<stdio.h>
#include<stdlib.h>
#include"multiStack.h"

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

int peep(STACK* p, digit* n)
{
    if(isEmpty(p));
        return 0;
    *n = p->top->info;
    return 1;
}

void push(STACK* p, digit n)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = n;
    temp->next = p->top;
    p->top = temp;
}

int pop(STACK* p, digit* n)
{
    *n = p->top->info;

    if(isEmpty(p))
        return 0;

    NODE* temp = p->top;
    p->top = p->top->next;
    free(temp);

    return 1;
}