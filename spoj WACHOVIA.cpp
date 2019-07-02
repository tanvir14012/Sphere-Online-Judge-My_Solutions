#include <bits/stdc++.h>
using namespace std;

inline int Max(int a,int b)
{
    return (a>b)?a:b;
}
int dp(int n, int KC, int w[],int v[])
{
    int T[n+1][KC+1];
    for(int i = 0; i<=KC; i++)///Case for first item.
    {
        if(w[0] <= i)
        {
            T[0][i] = v[0];
        }
        else
        {
            T[0][i] = 0;
        }
    }
    for(int i = 1; i<=n; i++)///Case for other items.
    {
        for(int j = 0; j<=KC; j++)
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
    int n,KC,ans,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&KC,&n);
        int v[n],w[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&v[i]);
        }
        ans = dp(n-1,KC,w,v);
        //cout<<"Hey stupid robber, you can get "<<ans<<"."<<endl;
        printf("Hey stupid robber, you can get %d.\n",ans);
    }
    return 0;
}
