//Addition of two Polynimials using Singly Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}NODE;

typedef struct list{
    NODE* head;
}SLL;

int initList(SLL*);
int createList(SLL*);
void delNode(SLL*);
void disp(SLL*);