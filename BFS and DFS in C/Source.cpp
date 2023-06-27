#include <stdio.h>
#include "Queue.h"

/**
 * \brief Breadth First Search using Adjacency Matrix.
 * \param G Matrix (Rows not required, only number of columns required to be passed in.)
 * \param start Starting Node
 * \param n Dimensions of the Matrix
 */
void BFS(int G[][7], int start, int n)
{
    int i = start;
    int visited[7]={0}; //initialized to 0 to indicate no Vertices have been visited

    printf("%d ", i);
    visited[i] = 1; //indicates this Vertex has been visited.
    enqueue(i);
    while(!isEmpty())
    {
        i = dequeue();
        for(int j=1; j<n; j++) //this loop takes you through all the elements of this index's row.
        {
            if(G[i][j]==1 && visited[j] == 0) //if there is an Edge at this location and the vertex has not been visited
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] ={0}; //static so it can be accessible in every call

    if(visited[start] == 0)
    {
        printf("%d, ", start);
        visited[start] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(G[start][i]==1 && visited[i]==0)
                DFS(G,i,n);
        }
    }
}

int main()
{
    //Adjacency Matrix, Set to 7x7 as there is no 0th index
    //and we want to skip that element so we can start at index 1
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

    DFS(G,4,7);

    return 0;
    }