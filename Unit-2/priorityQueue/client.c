#include <stdio.h>
#include <stdlib.h>

#include "priQueue.h"

int main()
{
    QUEUE* dataset = (QUEUE*)malloc(sizeof(QUEUE));
    init(dataset);

    int choice;

    do
    {
        NODE* element;
        printf("Chose option\n1. Enqueue\n2. Dequeue\n3. Display\n4. Check Empty\n0. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            element = (NODE*)malloc(sizeof(NODE));

        printf("Enter Data: ");
        scanf("%d",&(element->info));
        
        printf("Enter Priority: ");
        scanf("%d",&(element->pri));

        element->next=NULL;
        
        enQueue(dataset, element);
            break;
        
        case 2:
            if(deQueue(dataset, element))
                printf("\n%d(%d) dequeued\n\n",element->info,element->pri);
            else
                printf("\nQueue Empty\n\n");
            break;

        case 3:
            disp(dataset);
            break;
        case 4:
            isEmpty(dataset)?printf("\nQueue Empty\n\n"):printf("\nQueue not Empty\n\n");
            break;
        case 0:
            break;
            
        default:
            printf("\nINVALID OPTION\n\n");
            break;
        }
        
    }while(choice);


}