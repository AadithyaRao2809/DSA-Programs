#include<stdio.h>
#include<stdlib.h>

#include "doubly.h"

int main()
{
    DLL myList;
    init(&myList);

    createList(&myList);

    int choice;
    do
    {

        printf("1 Insert at pos\n\n2 Delete at pos\n\t3 Display\n\t0 Exit");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter postion to insert ");
            scanf("%d",&n);

            insertNode(&myList, n);

            printf("%d added to list", n);
            break;

        case 2:
            int n;
            printf("Enter postion to delete ");
            scanf("%d",&n);

            int res = deleteNode(&myList, n);

            printf("%d deleted",res);
            break;

        case 3:
            dispList(&myList);
        
        
        }
    } while (choice);
    
}