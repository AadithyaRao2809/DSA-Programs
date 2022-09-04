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

int createList(LIST*);
int dispList(LIST*);

int insertAt(LIST*, int);
int deleteKey(LIST*, int);
int mergeList(LIST*, LIST*);



