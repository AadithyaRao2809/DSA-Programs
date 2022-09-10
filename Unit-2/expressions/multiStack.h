union digits
{
    int i;
    char c;
};
typedef union digits digit;

typedef struct node
{
    digit info;
    int dType;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
} STACK;


void init(STACK*);
int isEmpty(STACK*);

int peep(STACK*, digit*);
void push(STACK*, digit);
int pop(STACK*, digit*);
