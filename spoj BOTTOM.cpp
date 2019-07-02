#include <bits/stdc++.h>
using namespace std;

class graph
{
private :
    int V;
    list<int> *adj;
public:
    graph(int V);
    void addEdge(int u,int v);
    void dfs1Until(int v,vector<bool> &visited,stack<int>& S);
    graph getTranspose();
    void dfs2Until(int v, vector<bool>&visited,vector<int>& scc);
    void findSCC();
};
graph::graph(int V)///constructor
{
    this->V = V;
    adj = new list<int>[V];
}
void graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void graph::dfs1Until(int v,vector<bool> &visited,stack<int>& S)
{
    visited[v] = true;
    for(list<int>::iterator it  = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(! visited[*it])///error prone
        {
            dfs1Until(*it,visited,S);
        }
    }
    S.push(v);///when no child remains, like topological sort huh!
}
graph graph::getTranspose()
{
    graph g(V);
    for(int i = 0; i<V; i++)
    {
        for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
        {
            g.addEdge(*it,i);
        }
    }
    return g;
}
void graph::dfs2Until(int v, vector<bool>&visited,vector<int>& scc)
{
    visited[v] = true;
    scc.push_back(v);
    for(list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(! visited[*it])///error prone
        {
            dfs2Until(*it,visited,scc);
        }
    }
}
void graph::findSCC()
{
    vector<bool> visited(V,false);
    stack<int>S;
    vector<vector<int> >SCC;
    for(int i = 0; i<V; i++)
    {
        if(! visited[i]) ///strongly error prone
        {
            dfs1Until(i,visited,S);
        }
    }

    graph g = getTranspose();

    visited.assign(V,false);
    int temp;

    while(! S.empty())
    {
        temp = S.top();
        S.pop();
        if(! visited[temp]) ///error prone
        {
            vector<int> scc;
            g.dfs2Until(temp,visited,scc);
            SCC.push_back(scc);
        }
    }
    ///Now all scc s are stored in SCC
    /**print strongly connected components
    for(int i = 0; i<SCC.size(); i++)
    {
        cout<<"SCC No: "<<i<<endl;
        for(int j = 0; j<SCC[i].size(); j++)
        {
            cout<<SCC[i].at(j)<<" ";
        }
        cout<<endl;
    }**/
    ///discard a scc if any vertex of it is connected to other than itself(connected to a different scc). Otherwise take it.
    vector<int>ans;
    for(int i = 0; i<SCC.size(); i++)
    {
        set<int>s;
        bool flag = false;
        for(int j = 0; j<SCC[i].size(); j++)
        {
            s.insert(SCC[i][j]);///all vertices are stored on set s.
        }
        for(int j = 0; j<SCC[i].size(); j++)
        {
            for(list<int>::iterator it = adj[SCC[i][j]].begin(); it != adj[SCC[i][j]].end(); it++)
            {
                if(s.find(*it) == s.end()) /// if any adjacent vertex is not connected to it's scc, then it must be connected
                    ///to a different scc, so set flag to discard whole the scc.
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false) ///all is connected to itself only, to take the whole
        {
            ans.insert(ans.end(),s.begin(),s.end());
        }
    }
    sort(ans.begin(),ans.end()); ///sort in increasing order as problem statement says.
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;

}
int main()
{
    int n,e,u,v;
    while(cin>>n)
    {
        if(n == 0)
        {
            break;
        }
        cin>>e;
        graph g(n);
        for(int i = 0; i<e; i++)
        {
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        g.findSCC();
    }
    return 0;
}
/***
Finding SCC:
Tusher Roy (fantastic) + geeksforgeeks.
first dfs is like topological sort.

The problem's algorithm:
Theorem : A strongly connected component (all vertices) is sink(i.e. all vertices are sink) if every vertex in a
scc is connected to no other scc than itself's.

Find all strongly connected component(scc)s by Kosaraju or Tarjan's algorithm and store them. Now, for every vertex in a scc, if you find an adjacent vertex
 (in the adjacency list) let's call it "v" such that v is not in that scc, then discard the whole scc. That is, when a vertex of a scc(No.1) is adjacent to
  a different scc(No.2) then discard scc(No.1), otherwise take all vertices of scc(No.1) to the "result" array or container. Do this for all scc s. After that,
   sort the "result" array and print it.
**/
