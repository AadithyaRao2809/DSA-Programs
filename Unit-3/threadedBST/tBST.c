#include<stdio.h>
#include<stdlib.h>

#include "tBST.h"


void init(NODE* tree)
{
    tree = NULL;
}


NODE* ins(NODE* root,int n)
{
    NODE* ele = malloc(sizeof(NODE));
    ele->data = n;
    ele->thread = 1;
    ele->left = NULL;
    ele->right = NULL;

    NODE* ptr = root;
    NODE* par = NULL;

    if(ptr == NULL)
        return root;

    while(ptr!=NULL)
    {
        par = ptr;
        if(n<ptr->data)
            ptr = ptr->left;
        

        if(n>ptr->data)
        {
            if(ptr->thread)
                break;
            ptr = ptr->right;    
        }
    }
    if(n < par->data)
    {
        par->left = ele;
        ele->right = par;
    }
    if(n > par->data)
    {
        ele->right = par->right;
        par->right = ele;
        par->thread = 0;
    }

    return root;

}


void traverse(NODE*);
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