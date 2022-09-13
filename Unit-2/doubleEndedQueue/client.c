#include <stdio.h>
#include <stdlib.h>

#include "doubleEnded.h"

int main()
{
    QUEUE myQueue;
    init(&myQueue);

    int choice;
    do
    {
        printf("\nChose Option\n1. Inset Front\n2. Insert Rear\n3. Delete front\n4. Delete Rear\n5. Display\n0. Exit");
        scanf("%d",&choice);

        int n;
        switch (choice)
        {
        case 1:
            printf("Enter Element to Queue: ");
            scanf("%d", &n);

            insertFront(&myQueue,n);
            printf("\n%d Queued to Front\n\n",n);

            break;
        case 2:
            printf("Enter Element to Queue: ");
            scanf("%d", &n);

            insertRear(&myQueue,n);
            printf("\n%d Queued to rear\n\n",n);
            break;
        case 3:
            if(deleteFront(&myQueue,&n))
                printf("\n%d Dequeued from front\n\n",n);
            else
                printf("Queue Empty");
            break;
        case 4:
            if(deleteFront(&myQueue,&n))
                printf("\n%d Dequeued from rear\n\n",n);
            else
                printf("\nQueue Empty\n\n");
            break;
        case 5:
            disp(&myQueue);
            break;
        case 0:
            break;

        default:
            printf("\nINVALID CHOICE\n\n");
            break;
        }
    } while (choice);
    

}
