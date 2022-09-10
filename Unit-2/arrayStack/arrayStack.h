#define MAX 10

typedef struct stack
{
    int s[MAX];
    int size;
}STACK;

void init(STACK*);
int peek(STACK*, int*);

int pop(STACK*, int*);
int push(STACK*, int);

