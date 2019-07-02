#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    list<int>*adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }
   void findTopologicalOrder(int u,vector<bool>& visited,stack<int>& S)
   {
       visited[u] = true;
       list<int>::iterator it;
       for(it = adj[u].begin(); it != adj[u].end(); it++)
       {
           if(visited[*it]==false)
           {
               findTopologicalOrder(*it,visited,S);
           }
       }
       S.push(u);
   }
    void topologicalSort(stack<int>& S)
    {
        vector<bool>visited(V,false);
        for(int i = 0; i!=visited.size(); i++)
        {
            if(visited[i]==false)
            {
                findTopologicalOrder(i,visited,S);
            }
        }
    }
};


int main()
{
    map<string,int>m;
    map<int,string>m1;
    string s1,s2;
    list<pair<string,string> >input;
    stack<int> S,nil;
    int t,n,counter;
    cin>>t;
    for(int i = 1; i<=t; i++)
    {
        cin>>n;
        counter = 0;
        n--;
        while(n--)
        {
            cin>>s1>>s2;
            input.push_back({s1,s2});
            if(m.find(s1) == m.end())
            {
                m[s1] = counter++;
                m1[counter-1] = s1;
            }
            if(m.find(s2) == m.end())
            {
                m[s2] = counter++;
                m1[counter-1] = s2;
            }
        }
        Graph g(m.size());
        for(auto it = input.begin(); it != input.end(); it++)
        {
            g.addEdge(m[it->first],m[it->second]);
        }
        g.topologicalSort(S);
        cout<<"Scenario #"<<i<<":"<<endl;
        while(!S.empty())
        {
            cout<<m1[S.top()]<<endl;
            S.pop();
        }
        cout<<endl;
        input.clear();
        m.clear();
        m1.clear();
    }
    return 0;
}
/**
I represented each string as a unique number by std::map,counter,and
input, then run topological sort, then decoded numbers to string.allocator_type*/
