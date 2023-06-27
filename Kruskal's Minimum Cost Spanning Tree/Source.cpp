#include <iostream>
#define I INT_MAX

using namespace std;

int edges[3][9] ={{1,1,2,2,3,4,4,5,5}, //first vertex
                  {2,6,3,7,4,5,7,6,7}, //second vertex
                  {25,5,12,10,8,16,14,20,18}}; //cost of the edges

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0}; //indicates whether an edge is included in the solution or not, 0 is not included and 1 is included
int t[2][6]; //stores the spanning tree solution

//Weighted Union
void Union(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u]+=set[v];
        set[v] = u;
    }
    else
    {
        set[v]+=set[u];
        set[u] = v;
    }
}

//Collapsing Find
int find(int u)
{
    int x=u, v=0;
    while(set[x]>0)
    {
        x = set[x];
    }
    while(u!=x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }

    return x;
}

int main()
{
    int i = 0, j, k, u, v, n = 7, e = 9, min = I;

    while(i < n-1)
    {
        min = I;

        //Finds the minimum cost edge
        for(j=0; j<e; j++)
        {
            //will only consider the edge if that edge has yet to be considered. if the value in included
            //is 1 then it has been added to the solution already. 
            if(included[j] == 0 && edges[2][j]<min)
            {
                min = edges[2][j];
                u =edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        //Checks to see if this edge forms a cycle or not, if these values are equal then they form a cycle and should not be included
        if(find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            Union(find(u), find(v));//Joins the parent Nodes (Heads of Sets)
            i++;
        }

        included[k] = 1;
    }

    for(i=0; i<n-1;i++)
    {
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

    return 0;
}