#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 26

typedef struct node
{
    int isEOW;
    struct node *children[CHAR_SIZE];
} NODE;

void addWord(NODE *, char *);

NODE *createNode()
{
    NODE *temp = malloc(sizeof(NODE));

    for (int i = 0; i < CHAR_SIZE; i++)
        temp->children[i] = NULL;
    temp->isEOW = 0;
    return temp;
}
void addWord(NODE *root, char *str)
{
    if (str[1] == '\0')
    {
        root->isEOW = 1;
        return;
    }

    if (root = NULL)
        root = createNode();

    root = root->children[str[0] - 'a'];

    addWord(root, &str[1]);
}

void findStrings(NODE* root, char* pre)
{
    int i=0;
    while(root!=NULL && pre[i]!='\0')
    {
        root = root->children[pre[i]-'a'];
        i++;
    }
    if(root==NULL)
    {
        printf("No strings matched");
        return;
    }

    char strings[100] = {'\0'};
    int charCount = 0;


}

int main()
{
    NODE *root = NULL;

    do
    {
        char str[100];
        printf("enter a string: ");
        scanf("%s", str);

        addWord(root, str);

        int choice;
        printf("Do you want to enter a new string ");
        scanf("%d", &choice);
    } while (choice);

    return 0;
}
