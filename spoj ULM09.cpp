#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    int V;
    list<pair<int,int>>*adj;
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
    int primMst();
};
graph::graph(int V)
{
    this->V = V;
    adj = new list<pair<int,int>>[V+1];
}
void graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
int graph::primMst()
{
    int u,v,w,mst_cost;
    vector<int>key(V,INT_MAX),parent(V,-1);
    vector<bool>mstSet(V,false);
    list<pair<int,int>>::iterator it;
    key[0]  = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;

    pq.push(make_pair(0,0));///vertex and key both = 0
    while(! pq.empty())
    {
        u = pq.top().first;
        mstSet[u] = true;
        pq.pop();
        for(it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;///adjacent vertex of u, from adjancy list
            w = it->second;///cost of (u-v) edge
            if(mstSet[v] == false && key[v] > w)///v must be unvisited as src.(see pen-paper)
            {
                key[v] = w;///keeps minimum cost edge for vertex v by updating.
                parent[v] = u;
                pq.push(make_pair(v,w));///vertex-cost
            }
        }
    }
    mst_cost = 0;
    for(int i = 1 ; i != V; i++)
    {
        //cout<<" "<<key[i];
        mst_cost += key[i];
    }
    return mst_cost;

}
int main()
{
    int m,n,u,v,w,total_cost,mst_cost;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m == 0 && n == 0)
        {
            break;
        }
        graph g(m);
        total_cost = 0;
        for(int i = 0; i != n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g.addEdge(u,v,w);
            total_cost += w;
        }
        mst_cost = g.primMst();
        printf("%d\n",total_cost-mst_cost);
    }
    return 0;
}
