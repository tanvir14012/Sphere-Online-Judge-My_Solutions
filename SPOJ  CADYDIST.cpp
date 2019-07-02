#include <bits/stdc++.h>
using namespace std;

bool cp(long long int a,long long int b)
{
    if(a>b)
    {
        return true;
    }
    return false;
}
int main()
{
    long long int n;
    long double ans=0;

    while(cin>>n)
    {
        if(n==0)
        {
            break ;
        }
        long long int a[n],b[n];
        for(long long int i=0; i!=n; ++i)
        {
            cin>>a[i];
        }
        for(long long int i=0; i!=n; ++i)
        {
            cin>>b[i];
        }
        cin.sync();
        sort(a,a+n,cp);
        sort(b,b+n);
        for(long long int i=0; i!=n; ++i)
        {
            ans+=a[i]*b[i];
        }
        cout<<(long long int)ans<<endl;
        ans=0;
    }
    return 0;
}
