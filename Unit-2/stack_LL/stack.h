typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
} STACK;


void init(STACK*);
int isEmpty(STACK*);

int peep(STACK*, int*);
void push(STACK*, int);
int pop(STACK*, int*);
