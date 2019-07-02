#include <bits/stdc++.h>
using namespace std;

int last[1000001];
void update(int BIT[],int n,int idx,int val)
{
    while(idx <= n)
    {
        BIT[idx] += val;
        idx += (idx & (-idx));
    }
}
int getSum(int BIT[],int idx)
{
    int val = 0;
    while(idx > 0)
    {
        val += BIT[idx];
        idx = idx - (idx & (-idx));
    }
    return val;
}
struct query
{
    int x,y,order;
};
struct compare
{
    bool operator ()(const query &a, const query &b)
    {
        return a.y < b.y;
    }
};
int main()
{
    int n,q,u,v;
    scanf("%d",&n);
    int a[n],bit[n+1];
    memset(bit,0,sizeof bit);
    memset(last,-1,sizeof last);
    for(int  i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    int ans[q];
    memset(ans,0,sizeof ans);
    query input[q];
    for(int i = 0; i<q; i++)
    {
        scanf("%d%d",&u,&v);
        input[i].x = u-1;
        input[i].y = v-1;
        input[i].order = i;
    }
    sort(input, input+q, compare());
    int it = 0;
    for(int  i = 0; i<n; i++)
    {
        if(last[a[i]] != -1)
        {
            update(bit,n,last[a[i]]+1,-1);
        }
        update(bit,n,i+1,1);
        last[a[i]] = i;

        while(it < q and input[it].y == i)
        {
            ans[input[it].order] = getSum(bit,i+1) - getSum(bit,input[it].x);
            it++;
        }
    }

for(int i = 0; i<q; i++)
{
    printf("%d\n",ans[i]);
}
    return 0;
}
/**
15
1 2 3 4 5 5 5 8 8 6 7 9 2 4 6
1
1 15
*/
