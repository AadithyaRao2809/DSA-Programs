#include<stdio.h>
#include<stdlib.h>

#include "polyAdd.h"

int main()
{
    SLL poly1; 
    SLL poly2;
    SLL sum;

    initList(&poly1);
    initList(&poly2);

    printf("Poly1\n");
    createList(&poly1);
    disp(&poly1);
    putchar('\n');
    
    printf("Poly2\n");
   createList(&poly2);
    disp(&poly2);
    putchar('\n');

    
    initList(&sum);

    addPoly(&poly1, &poly2, &sum);
    printf("\n\nThe sum is\n");
    disp(&sum);
    putchar('\n');



    return 0;
}