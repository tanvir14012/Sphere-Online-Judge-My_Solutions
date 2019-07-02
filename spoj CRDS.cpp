#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    long long int ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        for(int i = 1; i<=n; i++)
        {
            ans += (i*2) + (i-1);
        }
        ans %= 1000007;
        cout<<ans<<endl;
    }
    return 0;
}
