#include<stdio.h>
#include<stdlib.h>

typedef struct  node{
    struct node* prev;
    int info;
    struct node* next;
}NODE;

typedef struct list
{
    NODE* head;
}DLL;

void init(DLL*);
void createList(DLL*);
void insertNode(DLL*, int);
void dispList(DLL*);


