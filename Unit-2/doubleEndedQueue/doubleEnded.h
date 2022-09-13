
typedef struct node
{
    struct node* prev;
    int info;
    struct node* next;
}NODE;

typedef struct queue
{
    NODE* head;
    NODE* tail;
}QUEUE;

void init(QUEUE*);

void insertFront(QUEUE*,int);
void insertRear(QUEUE*,int);

int deleteFront(QUEUE*,int*);
int deleteRear(QUEUE*,int*);

void disp(QUEUE*);
