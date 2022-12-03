#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int hash(char* srn, int size)
{
    return atoi(&srn[10])%size;
}


int main()
{
    int hashed = hash("pes1ug21cs025",13);
    printf("Hashed at %d",hashed);

    return 0;
}

