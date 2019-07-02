#include <bits/stdc++.h>
using namespace std;

class graph
{
private :
    int V;
    list<int> *adj;
    list<int> *revAdj;///to store the reversed graph
    int *scc;///array,index represents vertex, value represents the serial No. of scc(will be updated in Kosaraju's 2nd dfs)
public:
    graph(int V);
    void addEdge(int u,int v);
    void dfs1Until(int v,bool visited[],stack<int>& S);
    void dfs2Until(int v, bool visited[],int number);
    void findSCC();
    void printResult(int index,int sccNo,int counter);
};
graph::graph(int V)///constructor
{
    this->V = V;
    adj = new list<int>[V];
    revAdj = new list<int>[V];
    scc = new int[V];
}
void graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}
void graph::dfs1Until(int v,bool visited[],stack<int>& S)
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

void graph::dfs2Until(int v, bool visited[],int number)
{
    visited[v] = true;
    scc[v] = number;
    for(list<int>::iterator it = revAdj[v].begin(); it != revAdj[v].end(); it++)
    {
        if(! visited[*it])///error prone
        {
            dfs2Until(*it,visited,number);
        }
    }
}
void graph::findSCC()
{
    bool visited[V];
    memset(visited,0,sizeof(visited));
    stack<int>S;
    for(int i = 0; i<V; i++)
    {
        if(! visited[i]) ///strongly error prone
        {
            dfs1Until(i,visited,S);
        }
    }

    memset(visited,0,sizeof(visited));
    int temp,count = 0;

    while(! S.empty())
    {
        temp = S.top();
        S.pop();
        if(! visited[temp]) ///error prone, unvisited means it will be a new scc
        {
            dfs2Until(temp,visited,count);
            ++count;
        }
    }
    //prints total scc s
//    cout<<count<<endl;
//    for(int i = 0; i<V; i++)
//    {
//        cout<<i+1<<" scc=> "<<scc[i]<<endl;
//    }

    ///In the reversed graph, if any vertex has indegree > 0, it & it's scc siblings should be discarded.
    set<int>discarded;///stores the serial NO. of scc that should be discarded
    for(int i  = 0; i<V; i++)
    {
        for(list<int>::iterator it = revAdj[i].begin(); it != revAdj[i].end(); it++)
        {
            if(scc[i] != scc[*it])
            {
                discarded.insert(scc[*it]);///watch out: *it. Here, *it has indegree 1
            }
        }
    }

    int counter = count - discarded.size();///stores number of un-discarded scc

    if(counter == 1)///If there is only one scc with indegree = 0, it is the solution otherwise no solution exists.
    {
        int num;
        for(int i = 0; i<count; i++)
        {
            if(discarded.find(i) == discarded.end())
            {
                num = i;
                break;
            }
        }
        printResult(V-1,num,0);
        printf("\n");
    }
    else
    {
        printf("0\n");
    }

}
void graph::printResult(int index,int sccNo,int counter) ///my fancy recursive printer
{
    if(index == -1)
    {
        printf("%d\n",counter);
        return ;
    }
    else
    {
        if(scc[index] == sccNo)
        {
            printResult(index-1,sccNo,counter+1);
            printf("%d ",index+1);
        }
        else
        {
            printResult(index-1,sccNo,counter);
        }

    }
}
int main()
{
    int n,e,u,v;
    scanf("%d%d",&n,&e);

    graph g(n);

    for(int i  = 0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        g.addEdge(u-1,v-1);
    }
    g.findSCC();
    return 0;
}
/**
Algorithm : Kosaraju's for scc (Tusher roy + geeksforgeeks).

Theorem:
(*) If you reverse all edges (they are unidirectional), then, the required city would be one
from which all other cities are reachable in the new graph. This does not work on the original graph
as this graph might have cycles.

(*)But observe that if a graph has a cycle, and one particular city in this cycle is such that every
 other city is reachable from this node, then the same is true for all nodes in that cycle.

 If you reverse the graph after finding scc's, (make all edges opposite) SCC's will remain connected
 like before.

(*)This is a good hint that we should find all the strongly connected components and get an acyclic
graph. The first reaction would be to carry out a DFS from all nodes one by one on this new graph and
check if all SCCs are reachable from a vertices, if yes then take the scc as result. That,
however, will time out for obvious reasons. I have got TLE here.

(*) Now let's store all SCCs(can be stored in 1D array i.e. index = vertex no., value = serial no.
of the scc, the vertex corresponds to) by Kosaraju's algorithm and reverse the graph and consider
a scc as a single vertex.
A useful observation is that  (**)In the reversed graph, only a node with in-degree 0 can be the
required node. Further, if you have multiple nodes with in-degree 0, we don’t have any city that
is reachable from all other cities. How ?

An in-degree of 0 in the new graph(reversed) signifies that there is no outgoing edge from this node
which means that this node would necessarily have to be a candidate city. So, if there are 2 nodes
in an acyclic graph with in-degree 0, both these nodes are not accessible from one another. So, both
of them can’t be a capital city (Simulate test cases for clearance).

So, the existence of capital cities implies that only one such node exists whose in-degree is 0.
If there is no such node, or if there are more than 1 node, the answer is 0. Else, we find the
original nodes that make up the strongly connected component and list them as the answer.

**/

