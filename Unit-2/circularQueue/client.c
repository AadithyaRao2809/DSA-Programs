#include<stdio.h>
#include<stdlib.h>

#include "circularQueue.h"

int main()
{
    QUEUE myQueue;
    init(&myQueue);

    int choice;
    do
    {
        printf("Chose operation:\n1. Enqueue\n2. Dequeue\n3. Check Full\n4. Check Empty\n5. Dsiplay Queue\n0. Exit\n");
        scanf("%d", &choice);

        int n;
        switch (choice)
        {
        case 1:
            printf("Enter number to enueue: ");
            scanf("%d",&n);
            if(enQueue(&myQueue, n))
                printf("\n%d added to queue\n\n",n);
            else
                printf("\nQueue Full\n\n");
            break;
        case 2:
            if(deQueue(&myQueue, &n))
                printf("\n%d removed from queue\n\n",n);
            else
                printf("\nQueue Empty\n\n");
            break;
        case 3:
            if(isFull(&myQueue))
                printf("\nQueue Full\n\n");
            else
                printf("\nQueue not Full\n\n");
            break;
        case 4:
            if(isEmpty(&myQueue))
                printf("\nQueue Empty\n\n");
            else
                printf("\nQueue not Empty\n\n");
            break;
        case 5:
            disp(&myQueue);
            break;
        case 0:
            break;
        
        
        default:
            printf("\nINVALID OPTION\n\n");
            break;
        }
    } while (choice);
    
}

