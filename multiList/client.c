#include<stdio.h>
#include<stdlib.h>

#include "multiList.h"

int main()
{
    MLIST* myList = (MLIST*)malloc(sizeof(MLIST));

    initList(myList);

    createSubs(myList);

    dispSubs(myList);


    return 0;
}