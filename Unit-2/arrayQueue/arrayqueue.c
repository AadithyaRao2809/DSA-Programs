#include <stdio.h>

#define MAX 10

typedef struct queue{
    int q[MAX];
    int front;
    int rear;
}QUEUE;

void init(QUEUE* p)
{
    p->rear = -1;
    p->front = 0;
}

int isEmpty(QUEUE* p)
{
    if(p->rear > p->front)
        return 1;
    return 0;
}

int isFull(QUEUE* p)
{
    if(p->rear > MAX)
        return 0;
    return 1;
}

int enQueue(QUEUE* p, int n)
{
    if(isFull(p))
        return 0;
    p->q[++p->rear] = n;
    return 1;
}

int deQueue(QUEUE* p, int* n)
{
    if(isEmpty(p))
        return 0;
    *n = p->q[p->front--];
    return 1;
}

