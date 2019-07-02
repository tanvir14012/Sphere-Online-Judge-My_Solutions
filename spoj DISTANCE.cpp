#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,first=0,second=0;
    long long int temp=0,ans=0;
    scanf("%d%d",&n,&d);

    int a[n][d];

    for(size_t i=0; i<n; i++)
    {
        for(size_t j=0; j<d; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(size_t i=0;i<n;i++)
    {
    for(size_t k=0;k<n;k++)
    {
        if(i==k){continue;}

        temp=0;
        for(size_t j=0;j<d;j++)
        {
            temp+=abs(a[i][j]-a[k][j]);
        }
        if(temp>ans)
        {
            ans=temp;
        }
    }
    }
    printf("%lld\n",ans);
    return 0;
}
