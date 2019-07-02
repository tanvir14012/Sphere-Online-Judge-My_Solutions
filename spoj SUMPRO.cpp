#include <bits/stdc++.h>
using namespace std;
#define L long long unsigned
L n;

L sum(L up, L down)
{
    if(up>down)
    {
        return 0;
    }
    else if(up==down)
    {
        return (L)(n/up)*up;
    }
    else if(up<down)
    {
        L temp=((down*(down+1))-(up*(up-1)))/2;
        return temp;
    }
}
int main()
{
    L t,ans,temp,up,down;
    cin>>t;
    while(t--)
    {
        cin>>n;
         ans=0;
         temp=(L)(sqrt(n));

        for(size_t i=1;i<=temp;i++)
        {
            down=(L)n/i;
            up=(L)(down/2)+i;
            ans+=(L)(down*i)+(sum(up,down)*i);
            ans%=1000000007;
        }

        //ans=ans%1000000007;
        cout<<ans<<endl;
    }
    return 0;
}
