#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}NODE;

typedef struct list
{
    NODE* head;
}CLL;

void init(CLL*);
int createList(CLL*);
int insertNode(CLL*, int);


int add(CLL*, CLL*, CLL*);
void disp(CLL*);

