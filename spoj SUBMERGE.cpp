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
public:
    graph(int V);
    void addEdge(int u,int v);
    void findAPs();
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
    int child = 0; ///watch-out, variable declared, so it is used
    ///to count independent(unconnected to each other) children(adjacent vertices) of u

    for(list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++)
    {
        if( ! visited[*it])
        {
            parent[*it] = u;
            child++;
            ///do the same process or *it as current node
            dfsUntil(*it,visited,ap,parent,lowTime,visitTime);///new push(function call) request to system stack from
///this point.So, all required task for that call (memory allocation,execution,pop) will be completely done and finally control will pass to next line.
            ///Traversing back
            ///Strictly speaking, u = current node,*it = adjacent node.
            ///case:1
            if(parent[u] == -1 && child >= 2)
            {
                ap[u] = true;
            }
            ///case:2
            else if(parent[u] != -1 && visitTime[u] <= lowTime[*it])
            {
                ap[u] = true;
            }
            ///updating low time before leaving
            lowTime[u] = Min(lowTime[u], lowTime[*it]);
        }
        else if(parent[u] != *it)
        {
            lowTime[u] = Min(lowTime[u],visitTime[*it]);///Tusher Roy(video) has a bug here
        }
    }


}
void graph::findAPs()
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
    int ans = 0;
    for(int i = 0 ; i<V; i++)
    {
        if(ap[i] == true)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int v,e,u,w;
    while(scanf("%d%d",&v,&e) != EOF)
    {
        if(v == 0 && e == 0)
        {
            break;
        }
        graph g(v+1);
        for(int i = 0; i<e; i++)
        {
            scanf("%d%d",&u,&w);
            g.addEdge(u,w);
        }
        g.findAPs();
    }
    return 0;
}

