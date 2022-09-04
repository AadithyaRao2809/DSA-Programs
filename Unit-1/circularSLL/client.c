#include<stdio.h>
#include<stdlib.h>

#include "circ.h"

int main()
{
    CLL n1;
    CLL n2;
    CLL sum;

    init(&n1);
    init(&n2);
    init(&sum);

    createList(&n1);
    printf("Number is ");
    disp(&n1);
    putchar('\n');
    createList(&n2);

    add(&n1, &n2, &sum);

    printf("Sum is ");
    disp(&sum);
}