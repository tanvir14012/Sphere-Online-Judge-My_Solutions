#include <bits/stdc++.h>
using namespace std;

long long int f(int n);
long long int temp=0;
map<int,long long int>a;

int main()
{
    int n,ct=0;
    long long int ans;
    while(scanf("%d",&n) != EOF)
    {
        temp=0;
        ans=f(n);
        printf("%lld\n",ans);
        ++ct;
        if(ct==10)
        {
            break;
        }
    }
    return 0;
}


long long int f(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(a[n] != 0)
    {
        return a[n];
    }
    else
    {
        if(a[n]==0)
        {
            temp=f(n/2)+f(n/3)+f(n/4);
        }
        if(n>temp)
        {
            a[n]=n;
        }
        else
        {
            a[n]=temp;
        }
        return a[n];
    }
}
