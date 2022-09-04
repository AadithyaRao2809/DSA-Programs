#include<stdio.h>
#include<stdlib.h>

#include "op.h"


int main()
{
    LIST* myList = (LIST*)malloc(sizeof(NODE));
    init(myList);
    createList(myList);

    int choice;
    do{
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter postion to insert ");
            int n;
            scanf("%d",&n);

            insertAt(myList, n);

            break;

        case 2:
            printf("Enter key to delete ");
            int key;
            scanf("%d",&key);

            deleteKey(myList, key);

            break;

        case 3:
            dispList(myList);
            break;       
        }
    } while (choice);
    

    return 0;
}