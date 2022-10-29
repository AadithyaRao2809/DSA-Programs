#include <stdio.h>
#define MAX 10

#define left(x) 2*x+1
#define right(x) 2*x+2

typedef struct treeNode
{
    int data;
    int used;
}NODE;

void init(NODE* tree)
{
    for(int i=0; i<MAX; i++)
        tree[i].used = 0;
}

int isert_node(NODE* tree, int n)
{

}

void create(NODE* tree)
{
    int cont,n;
    do
    {
        int p =0;
        if(p<MAX)
        {
            printf("Enter number: ");
            scanf("%d",&n);
        }

        while(p<MAX && tree[p].used!=0)
        {
            if(n<tree[p].data)
                p = left(p);
            else 
                p = right(p);
        }
        if(p>=MAX)
            return;
            
        tree[p].used = 1;
        tree[p].data = n;
        printf("p is now %d\n", p);



        printf("Do you want to continue: ");
        scanf("%d",&cont);
        

    }while(cont);
}

void inOrder(NODE* tree, int p)
{
    if(p>=MAX || !tree[p].used)
        return;

    inOrder(tree,left(p));
    printf("%d ",tree[p].data);
    inOrder(tree,right(p));
}

int main()
{
    NODE tree[MAX];

    init(tree);
    create(tree);
    inOrder(tree,0);
}