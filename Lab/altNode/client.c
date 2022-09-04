#include<stdio.h>
#include<stdlib.h>

#include "altNodes.h"

int main()
{
    SLL myList;
    initList(&myList);

    createList(&myList);
    printf("The List is\n");
    disp(&myList);

    delNode(&myList);

    printf("\nThe List after deltetion is\n");
    disp(&myList);


    


}