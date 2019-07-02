#include <bits/stdc++.h>
using namespace std;

int Min(int a,int b)
{
    return (a<b)?a:b;
}

class graph
{
private :
    int V;
    list<int> *adj;
    list<pair<int,int> >bridges;
public:
    graph(int V);
    void addEdge(int u,int v);
    void findBridges();
    void dfsUntil(int u, vector<bool>& visited, vector<bool>& ap,
    vector<int>& parent, vector<int>& lowTime, vector<int>& visitTime);

};
graph::graph(int V)///constructor
{
    this->V = V;
    adj = new list<int>[V];
}
void graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void graph::dfsUntil(int u, vector<bool>& visited, vector<bool>& ap,
    vector<int>& parent, vector<int>& lowTime, vector<int>& visitTime)
    {
        static int time = 0;
        visited[u] = true;
        lowTime[u] = visitTime[u] = ++ time;
        ///to count independent(unconnected to each other) children(adjacent vertices) of u

        for(list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if( ! visited[*it])
            {
                parent[*it] = u;
                ///do the same process or *it as current node
                dfsUntil(*it,visited,ap,parent,lowTime,visitTime);///new push(function call) request to system stack from
///this point.So, all required task for that call (memory allocation,execution,pop) will be completely done and finally control will pass to next line.
///Notice: lowTime[*it] will be updated i.e. that is minimum(itself,lowTime[adjacent]) -->all adjacents.
///Traversing back
///Strictly speaking, u = parent node in dfs tree(current node),*it = child node in dfs tree(Had to adjacent).
                ///updating low time before leaving
                lowTime[u] = Min(lowTime[u], lowTime[*it]);

                ///case for an edge to be a bridge
                if(lowTime[*it] > visitTime[u])
                {
                    bridges.push_back({u,*it});
                }
            }
            else if(parent[u] != *it)
            {
                lowTime[u] = Min(lowTime[u],visitTime[*it]);///Tusher Roy(video) has a bug here, he said min(,lowTime[*it]) which is wrong.
            }
        }


    }
void graph::findBridges()
{
    vector<bool>visited(V,false),ap(V,false);
    vector<int>parent(V,-1),lowTime(V,0),visitTime(V,0);

    for(int i = 0 ; i<V; i++)
    {
        if(! visited[i])
        {
            dfsUntil(i,visited,ap,parent,lowTime,visitTime);
        }
    }
    if(bridges.size()==0)
    {
        printf("Sin bloqueos\n");
    }
    else
    {
    bridges.sort();
    cout<<bridges.size()<<endl;
    for(list<pair<int,int> >::iterator it = bridges.begin(); it != bridges.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    }

}
int main()
{

    int t,n,e,u,v;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++)
    {
       scanf("%d%d",&n,&e);
       graph g(n+100);
       for(int j = 0; j<e; j++)
       {
           scanf("%d%d",&u,&v);
           g.addEdge(u,v);
       }
       printf("Caso #%d\n",i);
       g.findBridges();
    }
    return 0;
}
/***
Task : Find and print bridges in a undirected graph.

Learned from geeksforgeeks, it is highly related with articulation points(tusher roy).
Bridge:An edge in an undirected connected graph is a bridge iff removing it disconnects the graph

Theorem:In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exit any other
alternative to reach u or an ancestor of u from subtree rooted with v.

Case :After all child of u are dfsed, if lowTime[*it] > visitTime[u] then edge(u,*it) is a bridge.
**/
/**
Important** :The value lowTime[v] indicates the time of earliest visited vertex reachable from subtree rooted
with v (from v or any child(normal,grand,great grand-child..) of v). The recursive call dfsUntil(.,...) inside
loop does the job for children of u.
*/

