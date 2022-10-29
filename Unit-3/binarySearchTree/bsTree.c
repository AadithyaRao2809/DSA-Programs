#include<stdio.h>
#include<stdlib.h>

#include "bsTree.h"

NODE* createNode(int e)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = e;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
void createTree(TREE* tree)
{
    int n;
    NODE* temp;
    printf("Enter Number: ");
    scanf("%d",&n);
    tree->root = createNode(n);

    int cont;
    printf("Do you want to add element ");
    scanf("%d",&cont);

    while(cont)
    {
        int n;
        printf("Enter Number: ");
        scanf("%d",&n);
        temp = createNode(n);
        
        NODE* pres = tree->root;
        NODE* prev = NULL;

        while(pres!=NULL)
        {
            if(n<pres->info)
            {    
                prev = pres;
                pres = pres->left;
            }
            else
            {
                prev = pres;
                pres = pres->right;
            }
        }

        if(n<prev->info)
            prev->left = temp;
        else
            prev->right = temp;

        printf("Do you want to add element ");
        scanf("%d",&cont);
    }
}

void traverseTree(TREE* tree,void(*fun)(NODE*))
{
    if(tree->root==NULL)
        return;
    else
        fun(tree->root);
    
}


void inOrder(NODE* parent)
{
    if(parent == NULL)                                                                                                                                                                                                                                                                                                                                                  
        return;
    else
    {
        inOrder(parent->left);
        printf("%d ",parent->info);
        inOrder(parent->right);
    }
}

void preOrder(NODE* parent)
{
    if(parent == NULL)
        return;
    else
    {
        printf("%d ",parent->info);
        preOrder(parent->left);
        preOrder(parent->right);
    }
}

void postOrder(NODE* parent)
{
    if(parent == NULL)
        return;
    else
    {
        postOrder(parent->left);
        postOrder(parent->right);
        printf("%d ",parent->info);
    }
}

NODE* del(NODE* r, int d)
{
    NODE* temp = NULL;
    if(r == NULL)
        return r;
        
    if(d<r->info)
        r->left = del(r->left,d);

    if(d>r->info)
        r->right = del(r->right,d);

    if(d == r->info)
    {
        if(r->left == NULL)
        {
            temp = r->right;
            free(r);
            return temp;
        }
        if(r->right == NULL)
        {
            temp = r->left;
            free(r);
            return temp;
        }
        else
        {
            temp = r->right;
            while(temp->left != NULL)
                temp = temp->left;
            r->info = temp->info;
            r->right = del(r->right, temp->info);
        }
    }
    return r;
}