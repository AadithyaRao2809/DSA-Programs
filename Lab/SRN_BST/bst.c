#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
typedef struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
}NODE;

int my_strlen(char * s) 
{
    int count = 0; 
    while(*s !='\0')
    {
        s++;
        count++;
    }

    return count;
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    char* temp = str1;
    while(*str2 != '\0')
    {
        *temp = *str2;
        temp++;
        str2++;
    }
    *temp = '\0';
}

int my_strcmp(const char *a, const char *b)
{
    while(*a!='\0' && *b!='\0')
    {
        if(*a==*b)
        {
            a++; b++;
        }
        else if(*a>*b)
            return 1;
        else if(*a<*b)
            return -1;
        
    }
    if(*a!='\0')
    {
        return 1;
    }
    if(*b!='\0')
        return -1;
    if(*a!='\0' && *a!='\0')
        return 0;

}
//inserts elements into the tree
void insert(char* key, NODE** leaf)
{

    
    if(*leaf == NULL)
    {
        NODE* ele = (NODE*)malloc(sizeof(NODE));
        ele->p_right = NULL;
        ele->p_left = NULL;
        ele->value=key;
        *leaf = ele;
        return;
    }
    if(my_strcmp(key, (*leaf)->value)>0)
    {
        insert(key, &((*leaf)->p_right));
        
    }
    else if(my_strcmp(key, (*leaf)->value)<0)
    {
        insert(key, &((*leaf)->p_left));
    }
    else
        check = -1;
    

}



//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root==NULL)   
        return;
    asc_order(root->p_left);
    printf("%s\n",root->value);
    asc_order(root->p_right);
}



//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    if(leaf==NULL)
        return;
    
    if(my_strcmp(key,leaf->value)==0)
    {
        found = 1;
    }
    else if(my_strcmp(key,leaf->value)>0)
        search(key,leaf->p_left);
    else
        search(key,leaf->p_right);
}   




int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}
