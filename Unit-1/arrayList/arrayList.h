


#define MAX 5

typedef struct arrayList
{
    int arr[MAX];
    int index;

}ARRLST;



void init_list(ARRLST*);
int append(ARRLST*, int);
int del(ARRLST*, int*);
void disp_list(ARRLST*);
int left_shift(ARRLST*, int, int);
int right_shift(ARRLST*, int, int);