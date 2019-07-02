#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,ct=0,ans=0,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair<long long int,long long int>p[n];
        for(int i=0; i<n; ++i)
        {
            cin>>a>>b;
            cin.sync();
            p[i]=make_pair(a,b);
        }
        ct=0;
        for(long long int i=0; i!=n; ++i)
        {
            ct=0;
            for(long long int j=0; j!=n; ++j)
            {
                //cout<<p[j].first<<">="<<p[i].first<<endl;
                //cout<<p[j].second<<"<="<<p[i].second<<endl;
                if(i==j)
                {
                    continue;
                }
                else if(((p[j].first >= p[i].first) && ((p[j].first <= p[i].second)) || ((p[j].second <= p[i].second) && (p[j].second >= p[i].first))))
                {
                    ++ct;
                }
            }
            //cout<<"ct="<<ct<<endl;
            if(ct>ans)
            {
                ans=ct;

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**
1
5
1 7
2 4
6 9
3 8
5 10
**/
