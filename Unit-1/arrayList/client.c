#include<stdio.h>
#include<stdlib.h>

#include "arrayList.h"









int main()
{
    int choice;

    do
    {
        printf("1.Initialise\n2.Append\n3.Delete");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        ARRLST myList;
        init_list(&myList);

        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }

    } while (choice>0 && choice<4);
    



    return 0;
}




