

#include "arrayList.h"


void init_list(ARRLST* ap)
{
    ap->index = -1;
}



int append(ARRLST* ap, int n)
{
    if(ap->index == MAX)
        return 0;
    
    ap->arr[++(ap->index)] = n;
    return 1;

}

int del_last(ARRLST* ap, int* ep)
{
    if(ap->index == -1)
        return 0;
    
    *ep = ap->arr[--(ap->index)];
    return 1;
}

void disp_list(ARRLST* ap)
{
    for(int i=0; i<=(ap->index); i++)
    {
        printf("%d\t",ap->arr[i]);
    }
}


int left_shift(ARRLST* ap, int pos, int shifts)
{
    if(pos > ap->index || pos < 0)
        return 0;
    if((ap->index-pos < ap->index) || (shifts < 0))
        return 0;

    for(int i=pos; i<=ap->index; i++)
        ap->arr[i] = ap->arr[i+1];
    return 1;
}

int right_shift(ARRLST* ap, int pos, int shifts)
{
    if(pos > ap->index || pos < 0)
        return 0;
    if((ap->index-shifts < 0) || (shifts < 0))
        return 0;

    for(int i=pos; i<=ap->index; i++)
        ap->arr[i] = ap->arr[i+1];
    return 1;
}


