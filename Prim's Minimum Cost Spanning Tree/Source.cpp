#include <iostream>
#define I INT_MAX

using namespace std;

//Cost Adjacency Matrix which starts from (1,1) onwards.
int cost[][8]=
    {{I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}};

//Used to find which vertices are closest to one another. 0 is not used, array starts from index 1
int near[8] = {I,I,I,I,I,I,I,I};
//Stores the final spanning tree results
int t[2][6];

int main()
{
    int i,j,k,u,v, n = 7, min = I;

    //These two for loops will give us the minimum cost edge in the form of (u,v)
    for(i=1; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            //If the cost of the edge is less than min then we will store that cost in min.
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0; //We've included this Edge in the solution & we don't want to check it again, so we set it to 0. 

    //Compares u & v whichever has the lower cost will be recorded in near[] at location i.
    for(i = 1; i<=n; i++)
    {
        if(near[i]!=0)
        {
          if(cost[i][u] < cost[i][v])
            near[i] = u;
        else
            near[i] = v;  
        }
    }

    //We use n-1 in this for loop as we're looking for the rest of the edges for the spanning tree
    //and we've already filled the tree with 1 Edge. So we're looking for 1 less Edge.
    for(i=1; i < n-1; i++)
    {
        min = I;

        //finds the Edge with the minimum cost in the near[] and stores it in k.
        for(j =1; j<=n; j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        t[0][i]=k;
        t[1][i] = near[k];
        near[k] = 0; //Set to 0 as the Edge is already included in the tree and we don't want to compare it again.

        //Re-evaluates the cost of the Edges in near[] with consideration of k
        //if k has a lower cost then it will replace the value of j at that location.
        //indicating k is "closer" to the Edge.
        for(j=1; j<=n; j++)
        {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }

    for(i=0; i<n-1; i++)
    {
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

    return 0;
}