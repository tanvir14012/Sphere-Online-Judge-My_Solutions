#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main()
{
    int t,n,u,l,r,val,q,index;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&u);
        for(int i = 0; i<u; i++)
        {
            scanf("%d%d%d",&l,&r,&val);
            a[l] += val;
            if(r+1 < n) a[r+1] -= val;
        }
        for(int i = 1; i<n; i++)
        {
            a[i] += a[i-1];///making a prefix sum array
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&index);
            printf("%d\n",a[index]);
        }
        memset(a,0,sizeof(a));
    }
    return 0;
}
/**
Tricky.
Soln: For each update, increase the left index and decrease the right+1 index by "val".
After all update, simply make the array a prefix tree,which holds the soln.
**/

