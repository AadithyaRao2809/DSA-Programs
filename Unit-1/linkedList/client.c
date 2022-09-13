#include<stdio.h>
#include<stdlib.h>

#include "linkedList.h"


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
        case 6:
            int n;
            printf("the location to be inserted: ");
            scanf("%d", &n);
            insertAt(&myList, n);
            break;
        case 7:
            int key;
            printf("Enter the value to be deleted: ");
            scanf("%d", &key);
            deleteKey(&myList, key);
                  
        }

    }while(choice);


    return 0;
}