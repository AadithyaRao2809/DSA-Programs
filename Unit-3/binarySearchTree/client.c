#include<stdio.h>
#include<stdlib.h>

#include "bsTree.h"

int main()
{
    TREE* numbers = (TREE*)malloc(sizeof(TREE));
    numbers->root = NULL;

    createTree(numbers);

    int choice;
    printf("Pick an Option\n1. Print pre-order\n2. Print in-order\n3. Print post-order\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        traverseTree(numbers,&(preOrder));
        break;
    case 2:
        traverseTree(numbers,&(inOrder));
        break;
    case 3:
        traverseTree(numbers,&(postOrder));
        break;
    
    default:
        break;
    }
    


    return 0;
}