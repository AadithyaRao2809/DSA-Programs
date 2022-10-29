#include <stdio.h>
#include <stdlib.h>


typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{   
    for(int i=(heap->size/2)-1; i>=0; i--)
    {
        int ele = heap->arr[i];
        int k=i;
        int flag=0;
        while(!flag && 2*k+1<heap->size)
        {
            int j = 2*k+1;
            if(j+1<heap->size && heap->arr[j+1]<heap->arr[j])
                j++;
            if(ele<heap->arr[j])
                flag = 1;
            else
            {
                heap->arr[k] = heap->arr[j];
                k=j;
            }
            
        }
        heap->arr[k] = ele;
    }
}



void print_minheap(MinHeap* heap) {
    for(int i=0; i<heap->size; i++)
    {
        printf("%d ",heap->arr[i]);
    }
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}
