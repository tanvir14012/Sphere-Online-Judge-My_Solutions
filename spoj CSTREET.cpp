#include <bits/stdc++.h>
using namespace std;

int minIndex(int key[], bool mstSet[], int v)
{
    int index,minimum = INT_MAX;
    for(int i = 0; i != v; i++)
    {
        if(mstSet[i] == false && key[i] < minimum)
        {
            index = i;
            minimum = key[i];
        }
    }
    return index;
}

int prim(int **graph,int v)
{
    int key[v];
    bool mstSet[v];
    int u,mst_cost;
    memset(key,0,v*sizeof(int));
    memset(mstSet,0,v*sizeof(bool));

    for(int i = 0; i<v; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;

    for(int i = 0; i<v-1; i++)
    {
        u = minIndex(key,mstSet,v);
        mstSet[u] = true;
        for(int j = 0; j<v; j++)
        {
            int x =(int) *((graph+u*v) + j);
            if(x != 0 && mstSet[j] == false && key[j] > x)
            {
                key[j] = x; ///keeping the minimum cost for vertex j
            }
        }
    }
    mst_cost  = 0;
    for(int i = 1; i<v; i++)
    {
        mst_cost += key[i];
    }
    return mst_cost;
}
int main()
{
    int t,p,v,e,a,b,c,mst_cost,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&p,&v,&e);
        int graph[v][v];
        memset(graph,0,v*v*sizeof(int));
        for(int i = 0; i!=e; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            graph[a-1][b-1] = c;
            graph[b-1][a-1] = c;
        }
        //f((int **)graph);
        mst_cost = prim((int**)graph,v);
        ans = mst_cost * p;
        printf("%d\n",ans);
    }
    return 0;
}
/**
Prim's algorithm of O(V^2), learned from geeksforgeeks.
1
2
5
7
1 2 1
2 3 2
2 4 6
5 2 1
5 1 3
4 5 2
3 4 3
*/
