typedef struct node{
    
    int data;
    int thread;
    struct node* left;
    struct node* right;
}NODE;


void init(NODE*);
NODE* ins(NODE*,int);
int del(NODE*);
void traverse(NODE*);
