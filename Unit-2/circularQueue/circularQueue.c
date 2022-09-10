#include<stdio.h>
#include<stdlib.h>

#include "circularQueue.h"

void init(QUEUE* p)
{
    p->front = MAX-1;
    p->rear = MAX-1;
}

int enQueue(QUEUE* p, int n)
{
    if((p->rear+1)%MAX == p->front)
        return 0;
    p->rear = (p->rear+1)%MAX;
    p->q[p->rear] = n;
    return 1;
}


int deQueue(QUEUE* p, int* n)
{
    if(p->rear == p->front)
        return 0;
    p->front = (p->front+1)%MAX;
    *n = (p->q[p->front]);
    return 1;
}

int isEmpty(QUEUE* p)
{
    if(p->rear == p->front)
        return 1;
    return 0;
}


int isFull(QUEUE* p)
{
    if((p->rear+1)%MAX == p->front)
        return 1;
    return 0;
}

void disp(QUEUE* p)
{
    if(isEmpty(p))
    {
        printf("\nQueue Empty\n\n");
        return;
    }

    int n = p->front;
    printf("\nDiaplaying Elements\n");
    while(n!=p->rear)
    {
        n = (n+1)%MAX;
        printf("%d\n",p->q[n]);
    }
    printf("\n");
}