#include <bits/stdc++.h>
using namespace std;

class graph
{
private :
    int V;
    list<pair<int,int>> *adj;
public:
    graph(int V);
    void addEdge(int u,int v,int w);

    struct compare
    {
        bool operator ()(const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.second > b.second;
        }
    };

    void dijkstra(int src,int des);
};
graph::graph(int V)///constructor
{
    this->V = V;
    adj = new list<pair<int,int>>[V];
}
void graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void graph::dijkstra(int src,int des)
{
    int u,v,w;
    vector<int>distance(V,INT_MAX),parent(V,-1);
    vector<bool>visited(V,false);
    list<pair<int,int>>::iterator it;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
    distance[src] = 0;
    pq.push(make_pair(src,0));///source vertex & cost

    while(! pq.empty())
    {
       u = pq.top().first;
       visited[u] = true;
       pq.pop();
       for(it = adj[u].begin(); it != adj[u].end(); it++)
       {
           v = it->first;///vertex from adjacency list
           w = it->second;
           if(visited[v]==false && (distance[v] > distance[u]+w))///relaxation
           {
               distance[v] = distance[u]+w;
               parent[v] = u;
               pq.push(make_pair(v,distance[v]));
           }
       }
    }
    if(distance[des] != INT_MAX)
    {
        printf("%d\n",distance[des]);
    }
    else
    {
        printf("NONE\n");
    }
}

int main()
{
    int t,V,E,src,des,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&V,&E,&src,&des);
        graph g(V);
        for(int i = 0; i!=E; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g.addEdge(u-1,v-1,w);
        }
        g.dijkstra(src-1,des-1);
    }
    return 0;
}
