#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    int nodes,*parent,*ranks;
public:
    DisjointSet(int n)
    {
        nodes = n;
        parent = new int[n+1];
        ranks = new int[n+1];
        for(int i = 0; i<=n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
        }
    }
    int find(int u)
    {
        if(parent[u] != u)
        {
            parent[u] = find(parent[u]);///find + path compression
        }
        return parent[u];
    }
    void merge(int u,int v)
    {
        int x,y;
        x = find(u);
        y = find(v);

        if(ranks[x]>ranks[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
        if(ranks[x] == ranks[y])
        {
            ranks[y]++;
        }
    }
};
class Graph
{
    int V;
    list<pair<pair<int,int>,int> >edges;
public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u,int v,int w)
    {
        edges.push_back({{u,v},w});
    }
    struct compare
    {
        bool operator ()(const pair<pair<int,int>,int>&a, pair<pair<int,int>,int>& b)const
        {
            if(a.second < b.second)
            {
                return true;
            }
            return false;
        }
    } comparator;
    long kruskalMST()
    {
        int u,v,set_u,set_v;
        long long mst_weight = 0;
        list<pair<pair<int,int>,int>>::iterator it;

        edges.sort(comparator);
        DisjointSet ds(V);

        for(it = edges.begin(); it!=edges.end(); it++)
        {
            u = it->first.first;
            v = it->first.second;

            set_u = ds.find(u);
            set_v = ds.find(v);

            if(set_u != set_v)
            {
                //cout<<u<<"---"<<v<<endl;
                mst_weight += it->second;
                ds.merge(set_u,set_v);
            }
        }
        return mst_weight;
    }
};
int main()
{
    int e,n,temp,v,u,w;
    scanf("%d%d",&n,&e);
    Graph g(n);
        for(int i = 1; i<=e; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g.addEdge(u,v,w);
        }
        printf("%lld\n",g.kruskalMST());
    return 0;
}
/**
Tusher roy's video for disjoint set and video for checking cycle in a graph(using disjoint set)
this is direct kruskal, learned from geeksforgeeks.
I modified to use std::list<> and used std::list<>::sort(compare) and made a
custom comparator object.
*/

