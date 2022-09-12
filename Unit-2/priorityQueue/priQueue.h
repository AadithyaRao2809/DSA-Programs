#include <stdio.h>
typedef struct node
{
    int info;
    int pri;
    struct node* next;
}NODE;

typedef struct list
{
    NODE* head;
}QUEUE;

void init(QUEUE*);
void enQueue(QUEUE*,NODE*);
int deQueue(QUEUE*,NODE*);

void disp(QUEUE*);
int isEmpty(QUEUE*);

