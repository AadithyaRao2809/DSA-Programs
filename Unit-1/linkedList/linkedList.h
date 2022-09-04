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
}LIST;

void init(LIST*);
int insertFront(LIST*, int);
int deleteFront(LIST*, int*);

int insertLast(LIST*, int);
int deleteLast(LIST*, int*);

int dispList(LIST*);



