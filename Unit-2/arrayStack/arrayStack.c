#include "arrayStack.h"

void init(STACK* p)
{
    p->top = -1;
}

int peek(STACK* p, int* n)
{
    if(p->top == -1)
        return 0;
    
    *n = p->s[p->top];

    return 1;
}


int pop(STACK* p, int* n)
{
    if(p->top == -1)
        return 0;
    
    *n = p->s[p->top--];
    return 1;
}

int push(STACK* p, int n)
{
    if(p->top == MAX-1)
        return 0;
    
    p->s[++p->top] = n;
    return 1;   
}