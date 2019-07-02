#include <bits/stdc++.h>
using namespace std;
#define L unsigned long long
L modulo(L a,L n,L m);

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        L n,ans=0,temp=0;
        cin>>n;
        temp = modulo(34,n,11);
        ans=(((temp+(30*n)%11)%11) + (32%11))%11;

        ans=(11-ans)%11;
        cout<<ans<<endl;
    }
    return 0;
}

L modulo(L a,L n,L m)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        L y=modulo(a,n/2,m);
        return (y*y)%m;
    }
    else if(n%2==1)
    {
        return((a%m)*modulo(a,n-1,m))%m;
    }
}
