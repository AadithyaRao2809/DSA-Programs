#include "arrayStack.h"

void init(STACK* p)
{
    p->size = -1;
}

int peek(STACK* p, int* n)
{
    if(p->size == -1)
        return 0;
    
    *n = p->s[p->size];

    return 1;
}


int pop(STACK* p, int* n)
{
    if(p->size == -1)
        return 0;
    
    *n = p->s[p->size--];
    return 1;
}

int push(STACK* p, int n)
{
    if(p->size == MAX)
        return 0;
    
    p->s[++p->size] = n;
    return 1;   
}