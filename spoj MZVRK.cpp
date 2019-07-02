#include <bits/stdc++.h>
using namespace std;

long long int  f(long long int  x)
{
    if(x==0)
    {
        return 0;
    }
    if(x==1)
    {
        return 1;
    }
    if(x%2 == 0)
    {
        return (2*f(x/2)+(x/2));
    }
    else
    {
        return (2*f(x/2)+(x/2 +1 ));
    }

}

int  main()
{
    long long int  a,b,i,j,k,ans=0;
    cin>>a>>b;
    ans=f(b)-f(a-1);
    cout<<ans<<endl;

    return 0;
}
