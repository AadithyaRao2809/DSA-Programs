#include <stdio.h>
#include "stack.h"

int main()
{
    STACK myStack;
    init(&myStack);

    int choice;
    do
    {
        printf("\nChose option\n1. Peek into Stack\n2. Push to Stack\n3. Pop from Stack\n4. Check if Stack empty\n0. Exit\n\n");
        scanf("%d",&choice);

        int n, res;
        switch (choice)
        {
        case 0: break;

        case 1:
            res = peep(&myStack, &n);
            if(res)
                printf("\n%d at top of Stack\n\n",n);
            else
                printf("\nEmpty Stack\n\n");

            break;

        case 2:
            printf("\nEnter number to push: ");
            scanf("%d",&n);

            push(&myStack, n);
            printf("\n%d pushed\n\n",n);
            break;

        case 3:
            res = pop(&myStack, &n);
            if(res)
                printf("\n%d popped from Stack\n\n",n);
            else
                printf("\nEmpty Stack\n\n");
            break;

        case 4:
            res = isEmpty(&myStack);
            if(res)
                printf("\nEmpty Stack\n\n");
            else
                printf("\nNot Empty\n\n");
            break;

        default:
            printf("\nINVALID OPTION\n\n");
            break;
        }


    } while (choice);
    

    return 0;
}
