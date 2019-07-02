#include <bits/stdc++.h>
using namespace std;
#define ll long long unsigned

ll f(ll x,ll n, ll m)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n & 1) ///odd
    {
        return ((x%m)*f(x,n-1,m))%m;
    }
    else
    {
        ll y = f(x,n>>1,m);
        return (y*y)%m;
    }
}
int main()
{
    ll t,x,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>x>>n;
        ans = f(x,n,10);
        cout<<ans<<endl;
    }
    return 0;
}
