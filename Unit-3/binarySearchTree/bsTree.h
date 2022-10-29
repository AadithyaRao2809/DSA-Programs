typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}NODE;

typedef struct tree{
    NODE *root;
}TREE;

NODE* createNode(int);
void createTree(TREE*);
void traverseTree(TREE*,void(*fun)(NODE*));

void inOrder(NODE*);
void preOrder(NODE*);
void postOrder(NODE*);

NODE* del(NODE* r, int d);

