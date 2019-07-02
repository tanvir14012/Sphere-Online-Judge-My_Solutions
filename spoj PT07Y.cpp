#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    int V,E;
    list<int>*adj;
public:
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isTree()
    {
        vector<bool>visited(V,false);
        if(isCycle(0,visited,-1))
        {
            return false;
        }
        for(int i = 0; i<V; i++)
        {
            if(visited[i]==false)
            {
                return false;
            }
        }
        return true;
    }
    bool isCycle(int u, vector<bool>& visited, int parent)
    {
            visited[u] = true;
            for(auto it = adj[u].begin(); it!=adj[u].end(); it++)
            {
                if(*it != parent)
                {
                    if(visited[*it] == true)
                    {
                        return true;
                    }
                    else
                    {
                        if(isCycle(*it,visited,u)==true)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
    }
};
int main()
{
    int v,e,x,y;
    scanf("%d%d",&v,&e);
    graph g(v);
    for(int i = 0; i != e; i++)
    {
        scanf("%d%d",&x,&y);
        g.addEdge(x-1,y-1);
    }
    g.isTree()?cout<<"YES"<<endl : cout<<"NO"<<endl;
    return 0;
}
/**
Learned from geeks for geeks, isCycle() logic spinned for matching with tusher
roy's video, it's a dfs like approach.
Algorithm:
1.Run dfs from first vertex to detect cycle, keep a visited array.
2.If there is no cycle and no unvisited vertex it is a tree.
*/
