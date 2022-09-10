#include <stdio.h>
#include "arrayStack.h"

int main()
{
    STACK myStack;
    init(&myStack);
    
    int choice;

    do
    {
        printf("Choose Operations:\n1. Peek\n2. Pop\n3. push\n0. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            int num;
            int res;
        case 1:
            res = peek(&myStack, &num);
            if(res)
                printf("%d is at top of Stack\n",num);
            else
                printf("\nEmpty Stack\n\n");
            break;
        case 2:
            res = pop(&myStack, &num);
            if(res)
                printf("\n%d popped from Stack\n\n",num);
            else
                printf("\nEmpty Stack\n\n");
            break;
        case 3:
            printf("Enter number to push: ");
            scanf("%d",&num);
            res = push(&myStack, num);
            if(res)
                printf("\n%d pushed to Stack\n\n",num);
            else
                printf("\nStack Full\n\n");

            break;
        case 0:
            break;
        
        default:
        printf("\nINVALID OPTION\n\n");
            break;
        }
    } while (choice);
    
    return 0;
}