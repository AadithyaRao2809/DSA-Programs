#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node
{
    int id;             // ID of user
    int numfren;        // number of friends of user
    char name[MAX];     // name of user
    int *friends;       // friends of user as an user->friendsay
    struct node *right; // user to the right
    struct node *left;  // user to the left
} node;

struct node *retUser(char str[MAX])
{

    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    // copied ID
    char *token = strtok(str, ",");
    strcpy(ID, token);

    // copied Name
    token = strtok(NULL, ",");
    strcpy(name, token);

    // copied friends' ID
    token = strtok(NULL, ",");
    strcpy(strfriends, token);
    // printf("%s\n",(strfriends));

    // creating user nodes
    int id = atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id = id;
    user->friends = (int *)malloc(MAX * sizeof(int));
    strcpy(user->name, name);

    // adding user's friend's IDs
    token = strtok(strfriends, "|");
    int i = 0;
    while (token != NULL)
    {

        int temp = atoi(token);
        user->friends[i] = temp;
        i++;
        token = strtok(NULL, "|");
    }
    user->numfren = i;
    if (i == 0)
    {
        user->friends[i] = -1;
    }
    return user;
}


// search for user with id=key
struct node *search(int key, struct node *users)
{
    // printf("SEARCH START\n"); // DEBUG
    node *temp = NULL;

    if (users == NULL)
    {
        // printf("SEARCH END\n"); // DEBUG
        return NULL;
    }
    if (users->id == key)
    {
        // printf("SEARCH END\n"); // DEBUG
        return users;
    }

    if (users->id > key)
        temp = search(key, users->left);
    else
        temp = search(key, users->right);

    // printf("SEARCH END\n"); // DEBUG
    return temp;
    // DONE
}

// see document for explanattion

struct node *refineUser(struct node *user, struct node *users)
{
    // printf("REFINE START\n"); // DEBUG

    while (search(user->id, users) != NULL)
        user->id++;

    for (int i = 0; i < user->numfren;)
    {
        

        node *temp = search(user->friends[i], users);

        if (temp == NULL)
        {
            // printf("delete Start\n"); //DEBUG
            for(int j=i;j < user->numfren;j++)
                user->friends[j] = user->friends[j + 1];
            user->numfren--;
            // printf("delete End\n"); //DEBUG

        }
        else
        {
            temp->friends[temp->numfren++] = user->id;
            i++;
        }
    }

    // printf("REFINE END\n"); // DEBUG

    return user;
    // TODO
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    // printf("INSERT START\n"); // DEBUG

    user->id = id;
    user->left = NULL;
    user->right = NULL;

    if (root == NULL)
        return user;

    if (id < root->id)
        root->left = insertUser(root->left, id, user);
    else
        root->right = insertUser(root->right, id, user);
    return root;
    // DONE
}

// prints friends list
void friends(int id, struct node *users)
{
    // printf("FRIENDS START\n"); // DEBUG

    struct node *user = search(id, users);
    if(user == NULL)
        return;
        
    if(user->numfren==0)
    {
        printf("-1\n");//fix
        return;
        // printf("PRINTS-1"); //DEBUG
    }

    int i = 0;
    while (i < user->numfren)
    {
        printf("%d\n", user->friends[i]);
        i++;        
    }

    // DONE
}

// find child node with clsimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node)
{
    // printf("MINVAL START\n"); // DEBUG

    if (node->right == NULL)
        return NULL;

    node = node->right;
    while (node->left != NULL)
        node = node->left;

    return node;
    // DONE
}

// deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node *users)
{
    // printf("DELFRI START\n"); // DEBUG
    if (users == NULL)
        return NULL;
    deleteFriends(key, users->left);
    deleteFriends(key, users->right);

    int len = users->numfren;
    for (int i = 0; i < len; i++)
    {
        if (users->friends[i] == key)
        {
            for(int j=i; j<len;j++)
                users->friends[j] = users->friends[j+1];
            users->numfren--;

            if(users->numfren ==0)
                users->friends[0] = -1;
        }
    }

    // DONE
}

// Deleting a node
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
  
    if (key < root->id)
        root->left = deleteNode(root->left, key);
  
    else if (key > root->id)
        root->right = deleteNode(root->right, key);
  
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        struct node* temp = minValueNode(root);
  
        root->id = temp->id;
        root->numfren = temp->numfren;
        free(root->friends);
        root->friends = temp->friends;
        strcpy(root->name, temp->name);
  
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}
// Print USER's IDs in ascending order
void printInOrder(node *myusers)
{
    // printf("INORDER START\n"); // DEBUG

    if (myusers == NULL)
        return;

    printInOrder(myusers->left);
    printf("%d %s\n", myusers->id, myusers->name);
    printInOrder(myusers->right);
    // DONE
}

int main(int argc, char **argv)
{
    node *users = NULL;
    while (1)
    {

        int opt, id;
        // fflush(stdin);
        scanf("%d", &opt);
        char str[MAX];
        switch (opt)
        {
        case 1:

            scanf("%s", str);
            struct node *tbins = retUser(str);
            tbins = refineUser(tbins, users);
            users = insertUser(users, tbins->id, tbins);
            break;

        case 2:

            scanf("%d", &id);
            deleteFriends(id, users);
            users = deleteNode(users, id);
            break;

        case 3:

            scanf("%d", &id);
            node *result = search(id, users);
            if (result == NULL)
                printf("USER NOT IN TREE.\n");
            else
            {
                printf("%d\n", result->id);
            }
            break;

        case 4:
            scanf("%d", &id);
            friends(id, users);
            break;

        case 5:
            printInOrder(users);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Wrong input! \n");
            break;
        }
    }
    return 0;
}