#include <bits/stdc++.h>
using namespace std;

int Min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int t,k,temp;
    cin>>t;
    while(t--)
    {
        scanf("%*d%d",&k);
        int price[k+1],ans[k+1];
        for(int i = 0; i<k; i++)
        {
            cin>>price[i];
        }
        ans[0] = 0;
        for(int i = 1; i<=k; i++)
        {
            temp = 1001; ///like INT_MAX
            for(int j = 0; j<i; j++)
            {
                if((ans[i-1-j] == -1 || price[j] == -1) != true)
                {
                    temp = Min(temp, price[j] + ans[i-1-j]);
                }
            }
            ans[i] = temp;
        }
        if(ans[k] == 1001)
        {
            ans[k] = -1;
        }
        if(k == 0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<ans[k]<<endl;
        }
    }
    return 0;
}
/**
রড  cutting er উল্টো টা, মানে  k length এর জন্য minimum cost ই solution.
Any field's value "-1" means unavailable, so it must be skipped.
*/
