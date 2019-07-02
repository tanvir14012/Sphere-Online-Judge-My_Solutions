#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while(cin>>t)
    {
        if(t==-1)
        {
            break ;
        }
        int a[t],sum=0,logic=0,ans=0;

        for(int i=0;i<t;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        logic=sum/t;
        if(sum%t !=0)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=0;i<t;++i)
        {
            if(a[i] < logic)
            {
                ans+=(logic-a[i]);
            }
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}
