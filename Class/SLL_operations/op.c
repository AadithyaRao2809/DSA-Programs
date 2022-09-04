
#include "op.h"

void init(LIST *p)
{
    p->head = NULL;
}

int createList(LIST* p)
{
    int cont;
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    p->head = temp;
    temp->next = NULL;
    printf("Enter element to add");
    scanf("%d",&temp->info);

    printf("Continue? ");
    scanf("%d",&cont);
    
    while (cont)
    {
        temp = (NODE*)malloc(sizeof(NODE));
        temp->next = p->head;
        p->head = temp;

        printf("Enter element to add");
        scanf("%d",&temp->info);

        printf("Contine? ");
        scanf("%d",&cont);
    } 
    
}


int dispList(LIST *p)
{
    if (p->head == NULL)
        return 0;

    NODE *temp = p->head;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    return 1;
}


int insertAt(LIST* p, int n)
{
    NODE* temp = p->head;
    NODE* ele = (NODE*)malloc(sizeof(NODE));
    
    printf("Enter Element:");
    scanf("%d", &(ele->info));

    if(n<=0 || p->head==NULL)
    {
        ele->next = p->head;
        p->head = ele;
        return 1;
    }
    for(int i=0; i<n-1 && temp->next!=NULL; i++)
        temp = temp->next;

    ele->next = temp->next;
    temp->next = ele;
    return 1;    
}


int deleteKey(LIST* p, int key)
{
    NODE* del = p->head;
    NODE* prev = NULL;


    while(del!=NULL && del->info != key)
    {    
        prev = del;
        del = del->next;
    }

    if(del == NULL)
        return 0;
    
    if(del == p->head)
    {
        p->head = del->next;
        free(del);
        return 1;
    }
    prev->next = del->next;
    free(del);
    
    return 1;
}
