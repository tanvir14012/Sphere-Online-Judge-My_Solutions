#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    long long int ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(int i=0; i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n;i++)
        {
            cin>>b[i];
        }
        ans=0;
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0; i<n;i++)
        {
            ans+=a[i]*b[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
