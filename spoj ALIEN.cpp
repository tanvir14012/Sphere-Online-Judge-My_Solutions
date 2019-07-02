#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,ans1,l,count;
    long long int ans2,sum;
    cin>>t;
    while(t--)
    {
    cin>>n>>m;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    l = sum = ans1 = ans2 = count = 0;
    for(int i = 0; i<n; i++)
    {
        if(sum + a[i] <= m)
        {
            sum += a[i];
            count++;
        }
        else
        {
            while(sum + a[i] > m)
            {
                sum -= a[l];
                l++;
                count--;
            }
            sum+=a[i];
            count++;
        }
        if(count>ans1 || (count==ans1 && sum>ans2))
        {
            ans1 = count;
            ans2 = sum;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}
