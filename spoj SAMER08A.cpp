#include <bits/stdc++.h>
using namespace std;

class graph
{
private :
    int V,src,des;
    list<pair<int,int> > *adj;
    vector<int>distance;
    set<int>*parent;
    vector<bool>visited;
    deque<deque<int> >spath;
public:
    graph(int V,int src,int des);
    void addEdge(int u,int v,int w);

    struct compare
    {
        bool operator ()(const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.second > b.second;
        }
    };

    void dijkstra();
    void dfs(int source, int destination);
    void dfsUntil(int current, int destination,  vector<bool>& traversed, deque<int>& path);
    void printAllShortestPaths();
    int spojSAMER08A();
};
graph::graph(int V,int src,int des)///constructor
{
    this->V = V;
    this->src = src;
    this->des = des;
    adj = new list<pair<int,int> >[V];
    parent = new set<int>[V];
}
void graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
}
void graph::dijkstra()
{

    int u,v,w;
    list<pair<int,int> >::iterator it;
    distance.assign(V,INT_MAX);
    visited.assign(V,false);
    priority_queue<pair<int,int>, vector<pair<int,int> >, compare>pq;
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
            if(visited[v]==false && (distance[v] >= distance[u]+w))///relaxation
            {
                if((distance[v] > distance[u]+w))
                {
                    parent[v].clear();
                    parent[v].insert(u);
                }
                else

                {
                    parent[v].insert(u);
                }
                distance[v] = distance[u]+w;
                pq.push(make_pair(v,distance[v]));

            }
        }
    }

}
void graph::dfsUntil(int current, int destination,  vector<bool>& traversed, deque<int>& path)
{
    traversed[current] = true;
    path.push_front(current);

    if(current == destination)
    {
        spath.push_back(path);
        path.erase(path.begin(),path.end()-1);
        return ;
    }
    set<int>::iterator it;
    for(it = parent[current].begin(); it != parent[current].end(); it++)
    {
        dfsUntil(*it,destination,traversed,path);
    }
}
void graph::dfs(int source, int destination)
{
    vector<bool>traversed(V,false);
    deque<int>path;
    dfsUntil(source,destination,traversed,path);
}
void graph::printAllShortestPaths()
{
    dijkstra();
    dfs(des,src);
    deque<int>::iterator it;
    cout<<"All possible Shortest Paths :"<<endl;
    for(int i = 0; i != spath.size(); i++)
    {
        for(it = spath[i].begin(); it != spath[i].end(); it++)
        {
            cout<<*it<<"-->";
        }
        cout<<"Done "<<endl;
    }
}
int graph::spojSAMER08A()
{
    dijkstra();
    dfs(des,src);
    list<pair<int,int> >::iterator it;
    ///delete all edges of all shortest paths.
    for(int k = 0; k != spath.size(); k++)
    {
        for(int i = 0; i != spath[k].size()-1; i++)
        {
            int u = spath[k].at(i);
            int j = spath[k].at(i+1);
            for(it = adj[u].begin(); it!= adj[u].end(); it++)
            {
                if(it->first == j)
                {
                    adj[u].erase(it);
                    break;
                }
            }
        }
    }
//    cout<<"Adjacency list after all SP's are deleted : "<<endl;
//    for(int i = 0; i!=V;i++)
//    {
//        for(it = adj[i].begin(); it != adj[i].end(); it++)
//        {
//            cout<<i<<" "<<it->first<<" "<<it->second<<endl;
//        }
//    }
    ///Run dijkstra again.
    int u,v,w;
    distance.assign(V,INT_MAX);
    visited.assign(V,false);
    priority_queue<pair<int,int>, vector<pair<int,int> >, compare>pq;
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
            if(visited[v]==false && (distance[v] >= distance[u]+w))///relaxation
            {
                distance[v] = distance[u]+w;
                pq.push(make_pair(v,distance[v]));

            }
        }
    }
    if(distance[des] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return distance[des];
    }
}
int main()
{
    int V,e,src,des,u,v,w,ans;
    while(scanf("%d%d",&V,&e)!=EOF)
    {
        if(V == 0 && e == 0)
        {
            break ;
        }
        scanf("%d%d",&src,&des);
        graph g(V,src,des);
        for(int i = 0; i!=e; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g.addEdge(u,v,w);
        }
        ans = g.spojSAMER08A();
        printf("%d\n",ans);
    }
    return 0;
}
/**
correct approach:
1. Find all shortest paths by running dijkstra only once.
2. Delete all edges of all shortest paths from adjacency list.
3. Run dijkstra again after deletion and get correct output.

Find all shortest paths running dijkstra only once:
1.keep a parents of a vertex in a container like: set<int>s[V]. If a vertex has multiple parents of
same length then push all of them in the container. Like below:

if((distance[v] > distance[u]+w))
{
    parent[v].clear();
    parent[v].insert(u);
}
else

{
    parent[v].insert(u);
}
Now run a DFS in this parent container from destination vertex to find source vertex, if source vertex
is found then store the path in a container. Thus, all shortest paths can be found.

2. Use loops to delete SP edges from container.
3.Run actual dijkstra.
*/
