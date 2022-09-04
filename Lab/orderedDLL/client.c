#include<stdio.h>
#include<stdlib.h>

#include "order.h"

int main()
{
    DLL myList;
    init(&myList);

    createList(&myList);
    int cont;
    do
    {
        printf("Do you want to add element? ");
        scanf("%d",&cont);

        int n;
        printf("Do you want to add element? ");
        scanf("%d",&n);

        insertNode(&myList, n);
    } while (cont);
    

    dispList(&myList);
}