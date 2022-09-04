#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "multiList.h"

void initList(MLIST *p)
{
    p->subs = NULL;
}

SUB_ND *insertSub(MLIST *p, char *name)
{
    SUB_ND *ele = (SUB_ND*)malloc(sizeof(SUB_ND));
    ele->nextSub = NULL;
    ele->students = NULL;
    strcpy(ele->sub, name);

    if(p->subs == NULL)
    {
        p->subs = ele;
        return ele;
    }


    SUB_ND *temp = p->subs;
    while (temp->nextSub != NULL)
        temp = temp->nextSub;

    temp->nextSub = ele;

    return ele;
}

int insertStud(SUB_ND *p, char *name)
{
    STUD_ND *ele = (STUD_ND *)malloc(sizeof(STUD_ND));
    ele->nextStud = NULL;
    strcpy(ele->name, name);

    if(p->students == NULL)
    {
        p->students = ele;
        return 1;
    }

    STUD_ND *temp = p->students;
    while (temp->nextStud != NULL)
        temp = temp->nextStud;

    temp->nextStud = ele;
}

int createSubs(MLIST *p)
{
    int choice;
    do
    {
        char sub[21];
        printf("Enter Name of Subject: ");
        scanf("%s", sub);
        
        SUB_ND* subject =  insertSub(p, sub);
        createStuds(subject);

        printf("Do you Want to Continue? ");
        scanf("%d", &choice);

    } while (choice);
}

int createStuds(SUB_ND *p)
{
int choice;
    do
    {
        char name[51];
        printf("Enter Name of Student: ");
        scanf("%s", name);
        insertStud(p, name);

        printf("Do you Want to Continue? ");
        scanf("%d", &choice);

    } while (choice);
}

int dispStuds(SUB_ND* p)
{
    STUD_ND* temp = p->students;
    if(p->students == NULL)
    {
        printf("NA");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%s ",temp->name);

        temp = temp->nextStud;
    }
    

}

int dispSubs(MLIST* p)
{
    SUB_ND* temp = p->subs;
    if(p->subs == NULL)
    {
        printf("NA");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%s -->",temp->sub);
        dispStuds(temp);
        putchar('\n');

        temp = temp->nextSub;
    }
    return 1;
    
}
