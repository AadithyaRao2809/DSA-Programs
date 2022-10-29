#include<stdio.h>

#define MAX 10

void readMat(int a[MAX][MAX], int n)
{
    for(int i=0; i<n;i++)
        for(int j=0; j<=i; j++)
        {
            printf("is there a connct b/w %d & %d ",i,j);
            scanf("%d",&a[i][j]);
            a[j][i] = a[i][j];
        }
}

void bfs(int vrt, int adj[MAX][MAX],int n)  //iterative 
{
    int visited[MAX] = {0};
    int q[MAX];
    int f=0;
    int r=-1;

    q[++r] = vrt;
    visited[vrt] = 1;

    while(f<=r)
    {
        int k = q[f++];
        printf("%d\n",k);

        for(int i=0; i<n;i++)
        {
            if(adj[k][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;

            }
        }
    }

}


int dfs(int v, int adj[MAX][MAX], int visited[MAX],int n, int parent)   //recursion with loop check
{
    printf("%d\n",v);
    visited[v]=1;
    int res=0;
    for(int i=0; i<n; i++)
    {
        if(adj[v][i])
        {
            if(!visited[i])
                res = dfs(i,adj,visited,n,v);
            else if(i!=parent)
                res =  1;
        }
    }
    return res;
}

int main()
{
    int adj[MAX][MAX];
    int n;
    

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    readMat(adj,n);
    bfs(0,adj,n);
}

