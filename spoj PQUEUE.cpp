#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,ct,n,m,index,temp147;
    pair<int,int>p,temp;
    priority_queue <int> pq;
    queue<pair<int,int> >q;
    cin>>t;
    while(t--) {
            index = ct = 0;
        cin>>n>>m;
        int a[n];
        for(int i = 0; i<n; i++) {
            cin>>temp147;
            pq.push(temp147);
            q.push(make_pair(i,temp147));
        }

        while(index != m) {
        int x = pq.top();
        p = q.front();
        index = p.second;
        if(x == p.first && p.second == m) {
            ct++;
            break;
        }
        else if(x == p.first && p.second != m)
        {
            pq.pop();
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        else
        {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        }
        cout<<ct<<endl;
    }
    return 0;
}
