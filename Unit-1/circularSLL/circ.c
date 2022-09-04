#include<stdio.h>
#include<stdlib.h>

#include "circ.h"


void init(CLL* p)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    p->head = temp;
    temp->info = -1;

    temp->next = temp;
}
int createList(CLL* p)
{
    printf("Enter Number: ");

    char ch;
    int n;
    while ((ch=getchar())!='\n')
    {
        n = ch - '0';

        insertNode(p, n);
    }
    
    


}

int insertNode(CLL* p, int n)
{
    NODE* ele = (NODE*)malloc(sizeof(NODE));
    ele->info = n;
    
    NODE* temp = p->head;
    ele->next = temp->next;
    temp->next = ele;

}

int add(CLL* l1, CLL* l2, CLL* l3)
{
    NODE* p1 = l1->head->next;
    NODE* p2 = l2->head->next;

    int add = 0;
    int carry = 0;

    while((p1->info != -1) && (p2->info != -1))
    {
        add = p1->info + p2->info + carry;

        carry = add/10;
        insertNode(l3, add%10);

        p1 = p1->next;
        p2 = p2->next; 
        
    }

    while(p1->info != -1)
    {
        add = p1->info + carry;

        carry = add/10;
        insertNode(l3, add%10);

        p1 = p1->next;
    }

    while(p2->info != -1)
    {
        add = p2->info + carry;

        carry = add/10;
        insertNode(l3, add%10);

        p2 = p2->next;
    }

    if(carry)
        insertNode(l3, carry);

}

void disp(CLL* p)
{
    NODE* temp = p->head->next;

    while(temp->info != -1){
        printf("%d",temp->info);
        temp = temp->next;
    }
        
    
}