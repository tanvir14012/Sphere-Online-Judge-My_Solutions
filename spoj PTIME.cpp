#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sqN;
    cin>>n;
    int a[n+1],ans[n+1];
    sqN = (int) sqrt(n);
    bool prime[sqN];
    memset(prime,0,sqN);
    memset(ans,0,n+1);
    for(int i = 2; i<=n; i++)
    {
        a[i] = i;
    }
    for(int i = 2; i<=n; i++)
    {
        if(a[i]%2 == 0)
        {
            prime[i] = true;
            while(a[i]%2 == 0)
            {
                a[i]/=2;
                ans[2]++;
            }
        }
    }
    for(int j = 3; j<=sqN; j+=2)
    {
        for(int i = 3; i<=n; i++){
        if(prime[i]==false)
        {
            if(a[i]%i == 0)
            {
                while(a[i]%i == 0)
                {
                    a[i]/=i;
                    ans[i]++;
                }
            }
        }
    }
    }
    for(int i = 2; i<=sqN; i++)
    {
        if(prime[i]==false)
        {
            cout<<i<<"^"<<ans[i]<<" * ";

        }
    }
    return 0;
}
