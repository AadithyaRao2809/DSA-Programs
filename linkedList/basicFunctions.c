#include<stdio.h>
#include<stdlib.h>

#include "linkedList.h"
#define MAX 7


int main()
{
    LIST myList;

    init(&myList);

    int choice;
    do{
        printf("Enter Choice\n\t1 Insert Front\n\t2 Delete Front\n\t3  Insert Last\n\t4 Delete Last\n\t5 Display\n\t6 Exit");
        scanf("%d",&choice);

        int n;
        switch (choice)
        {
        case 1:
            printf("Enter Number: ");
            scanf("%d", &n);

            insertFront(&myList, n);
            break;
        
        case 2:
            deleteFront(&myList, &n);
            printf("\n%d\n",&n);
            break;

        case 3:
            printf("Enter Number: ");
            scanf("%d", &n);

            insertLast(&myList, n);
            break;
        
        case 4:
            deleteLast(&myList, &n);
            printf("\n%d\n",&n);
            break;
        case 5:
            dispList(&myList);
            break;            
        }

    }while(choice);


    return 0;
}