#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator ()(pair<long long,long long>& a, pair<long long,long long>& b)
    {
        return (a.second > b.second);
    }
};
int main()
{
    long long n,x,y;

    cin>>n;
    pair<long long,long long> a[n];
    vector<bool>mark(10003,false);
    long long ans = 0;
    for(long long i = 0; i<n; i++)
    {
        cin>>x>>y;
        a[i] = make_pair(x,y);
    }

    sort(a,a+n,compare());

    for(long long i = 0; i<n; i++)
    {
        pair<long long,long long> temp = a[i];

        while(temp.second > 0 )
        {
            if(mark[temp.second] == false)
            {
                mark[temp.second] = true;
                ans += temp.first;
                break;
            }
            temp.second--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
/*
4

 10 3

 7 5

 8 1

 2 1


 */
