#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

void init(LIST *p)
{
    p->head = NULL;
}

int insertFront(LIST *p, int n)
{
    NODE *ele = (NODE *)malloc(sizeof(NODE));

    if (ele == NULL)
        return 0;
    ele->info = n;

    ele->next = p->head;
    p->head = ele;
    return 1;
}

int deleteFront(LIST *p, int *e)
{
    if (p->head == NULL)
        return 0;
    *e = p->head->info;

    NODE *temp = p->head;
    p->head = p->head->next;

    free(temp);
    return 1;
}

int insertLast(LIST *p, int n)
{
    if (p->head == NULL)
    {

        NODE *ele = (NODE *)malloc(sizeof(NODE));
        if (ele == NULL)
            return 0;

        ele->info = n;

        ele->next = p->head;
        p->head = ele;

        return 1;
    }

    NODE *ele = (NODE *)malloc(sizeof(NODE));
    if (ele == NULL)
        return 0;

    ele->info = n;

    NODE *temp = p->head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = ele;
    ele->next = NULL;
    return 1;
}

int deleteLast(LIST *p, int *e)
{
    if (p->head == NULL)
        return 0;

    NODE *temp = p->head;

    while (temp->next->next != NULL)
        temp = temp->next;

    *e = temp->next->info;
    free(temp->next);
    temp->next = NULL;
    return 1;
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

