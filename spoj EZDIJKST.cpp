#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;


#define M 10000
#define INF INT_MAX
int dijkstra(int src, int n);

vector<pair<int,int> >a[M];
int visited[M];
int parent[M];
int dis[M];


int main()
{
    int n,e,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        for(int i=1; i<=e; ++i)
        {
            int x,y,w;
            cin>>x>>y>>w;
            a[x].push_back(make_pair(y,w));
           /// a[y].push_back(make_pair(x,w));//because that is a directed graph
        }
        int src,des;
        /// cout<<"Enter source node:"<<endl;
        cin>>src>>des;
        dijkstra(src,n);


        (dis[des]!=INF)?cout/**<<"-->"**/<<dis[des]<<endl:cout<<"NO"<<endl;

        memset(a,0,M);
        memset(visited,0,M);
        memset(dis,0,M);
        /*
        for(int i=0; i<M; ++i)
        {
            a[i].clear();
        }
        n=e=0;
*/
    }

    return 0;
}

int dijkstra(int src, int n)
{
    for(int i=1; i<=n; ++i)
    {
        dis[i]=INF;
    }
    class compare
    {
    public:
        bool operator()(pair<int,int>&p1, pair<int,int>&p2)
        {
            return p1.second>p2.second;
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int> >,compare>pq;
    pq.push(make_pair(src,dis[src]=0));

    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int u=p.first;
        int v=p.second;
        if(visited[u]==1)
        {
            continue;
        }
        visited[u]=1;

        for(int i=0; i<a[u].size(); ++i)
        {
            if(!visited[a[u].at(i).first] && v+a[u].at(i).second<dis[a[u].at(i).first])
            {
                dis[a[u].at(i).first]=v+a[u].at(i).second;
                parent[a[u].at(i).first]=u;
                pq.push(make_pair(a[u].at(i).first,dis[a[u].at(i).first]));
            }
        }
    }
}

/**
6 6
1 2 4
1 3 6
2 4 8
3 6 10
4 5 7
5 6 3

**/


