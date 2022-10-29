#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
    int info;
    struct node * link;
}NODE;

typedef struct list{
    NODE* head;
    int size;
}RING;

void create(RING*);
void init(RING*);
void display(RING*);
NODE* game(RING*, int, int);

int main()
{
    srand(time(0));
    RING ring;
    init(&ring);
    create(&ring);
    display(&ring);
    int start = rand()%(ring.size)+1;
    int skip = rand()%((ring.size)/2+1)+1;

    // int skip, start;

    // printf("Enter a start point: ");
    // scanf("%d",&start);

    // printf("Enter a skip value: ");
    // scanf("%d",&skip);

    printf("Start: %d Skip: %d\n",start,skip);
    
    NODE winner = *game(&ring, start, skip);
    printf("The winner is %d", winner.info);
    return 0;

}

void init(RING* ring)
{
    ring->head = NULL;
    ring->size = 0;
}

void create(RING* ring)
{
        NODE* point= (NODE*)malloc(sizeof(NODE));

        printf("Enter the node info: ");
        scanf("%d", &(point->info));
        ring->head = point;
        point->link = point;
        ring->size++;
        int choice;
        printf("Would you like to continue : ");
        fflush(stdin);
        scanf("%d", &choice);
    

    while(choice)
    {


        NODE * temp = (NODE*)malloc(sizeof(NODE));
        printf("Enter the node info: ");
        scanf("%d", &(temp->info));
        
        temp->link = ring->head;
        ring->head = temp;
        point->link = temp;

        ring->size++;

        printf("Would you like to continue : ");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        
    }
    
}

void display(RING* ring)
{
    if(ring->head == NULL)
    {
        printf("Empty");
        return;
    }

    NODE* temp = ring->head;
    do{
        printf("Element : %d\n", temp->info);
        temp = temp->link;
    }while(temp!=(ring->head));
}

NODE* game(RING* ring, int start, int skip)
{
    NODE* temp = ring->head;
    for(int i=0; i<start-1; i++)
    {
        temp = temp->link;
    }
    while(ring->size!=1)
    {
        NODE* prev = temp;
        for(int i = 0; i<skip; i++)
        {
            prev = temp;
            temp = temp->link;
            
        }
        printf("%d deleted\n",temp->info);
        prev->link = temp->link;
        free(temp);
        temp = prev;
        ring->size--;

    }
    return temp; 

}

