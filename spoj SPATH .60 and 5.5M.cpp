#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include<windows.h>
using namespace std;
#define INF 200000
#define sz 100005

vector<pair<int,int> >a[sz];

int dijkstra(int src,int des,int n)
{
int dis[sz];
int visited[sz];


    memset(visited,0,sz);
    memset(dis,0,sz);
    for(int i=1; i<=n; ++i)
    {
        dis[i]=INF;
    }

    class compare
    {
    public:
        bool operator ()(pair<int,int>&p1,pair<int,int>&p2)
        {
            return p1.second>p2.second;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int> >,compare>pq;
    pq.push(make_pair(src,dis[src]=0));

    while(!pq.empty())
    {
        pair<int ,int>p=pq.top();
        pq.pop();

        int u=p.first;
        int v=p.second;
        if(u==des)
        {
            // cout<<v<<endl; /// 'v' the final shortest distance for this vertex
            return v;
        }

        if(visited[u]==1)
        {
            continue;
        }
        visited[u]=1;

        for(int i=0; i<a[u].size(); ++i)
        {
            while(!visited[a[u].at(i).first] && a[u].at(i).second+v<dis[a[u].at(i).first])
            {
                dis[a[u].at(i).first]=a[u].at(i).second+v;
                pq.push(make_pair(a[u].at(i).first,dis[a[u].at(i).first]));
            }


        }


    }

    return INF;
}

int main()
{

    int t,n,i,j,x,w,num,e;

    string str,s1,s2;
    map<string,int>mp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

         for(int i=1; i<=n; ++i)
         {
             a[i].clear();
         }
        for(i=1; i<=n; ++i)
        {
            cin.sync();
            cin>>str;
             cin.sync();
            mp[str]=i;

            scanf("%d",&e);

            for(j=1; j<=e; ++j)
            {
                scanf("%d%d",&x,&w);
                a[i].push_back(make_pair(x,w));
            }

        }
        scanf("%d",&num);
        while(num--)
        {
            cin>>s1>>s2;
            cin.sync();
            //cin.clear();
            cout<<dijkstra(mp.find(s1)->second,mp.find(s2)->second,n)<<endl;
            //cin.clear();

        }
       /// memset(a,0,sz);
       /// mp.clear();

    }



Sleep(100000);

    return 0;
}



