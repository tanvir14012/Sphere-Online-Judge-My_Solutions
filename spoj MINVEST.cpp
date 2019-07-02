#include <bits/stdc++.h>
using namespace std;

inline long long int  Max(long long int  a,long long int  b)
{
    return (a>b)?a:b;
}
long long int  dp(long long int  n, long long int  KC, long long int  w[],long long int  v[])
{
    long long int  T[n+1][KC+1];
    for(long long int  i = 0; i<=KC; i++)///Case for first item.
    {
        T[0][i] = 0;
        if(w[0] <= i)
        {
            T[0][i] += v[0];
        }
        else
        {
            T[0][i] = 0;
        }
    }
    for(long long int  i = 1; i<=n; i++)///Case for other items.
    {
        for(long long int  j = 0; j<=KC; j++)
        {
            if(w[i] <= j)
            {
                T[i][j] = Max((v[i] + T[i-1][j-w[i]]), T[i-1][j]);
            }
                      else
            {
                T[i][j] = T[i-1][j];
            }
        }
    }
    return T[n][KC];
}
int main()
{
    int t,year;
    long long int KC,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d%lld",&KC,&year,&n);
    }
    long long int w[n],v[n];
    for(int i=0; i<n; i++)
    {
        scanf("%lld%lld",&w[i],&v[i]);
    }
    for(int i=0; i<year; i++)
    {
        ans = dp(n-1,KC,w,v);
        KC += ans;
        printf("______%lld\n",KC);
    }
    printf("%lld\n",KC);
    return 0;
}
