#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[ ][7],int start,int n)
{
    static int visited[7] = {0}; // we have made it statis so that it is available in each call

    if(visited[start] == 0)
    {
        printf(" %d",start);
        visited[start] = 1;
        for(int i=1;i<n;i++)
        {
            if(G[start][i] == 1 && visited[i]==0)
            DFS(G,i,n);
        }
    }
}
int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    BFS(G, 4, 7);
    DFS(G,1,7);
    return 0;
}