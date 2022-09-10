#define MAX 5

typedef struct queue
{
    int q[MAX];
    int rear;
    int front;
}QUEUE;
 
void init(QUEUE*);

int enQueue(QUEUE*, int);
int deQueue(QUEUE*, int*);

int isFull(QUEUE*);
int isEmpty(QUEUE*);
void disp(QUEUE*);
