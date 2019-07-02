#include <bits/stdc++.h>
using namespace std;
#define L long long int
int main()
{
    L t,n,*a;
    //cin>>t;
    scanf("%lld",&t);

    while(t--)
    {
        //cin>>n;
        scanf("%lld",&n);
        a=new L[n+1];
        //L a[n+1];
        L temp,ans=0;
        map<L,int>m;
        a[0]=0;
        for(size_t i=1;i<=n; ++i)
        {
            //cin>>a[i];
            scanf("%lld",&a[i]);
            a[i]=a[i]+a[i-1];
            m[a[i]]++;

        }
        for(map<L,int>::iterator it=m.begin(); it!=m.end(); ++it)
        {
            temp=it->second;
            if(it->first==0)
            {
                ans+=temp+(temp*(temp-1))/2;
            }
            else
            {
                ans+=(temp*(temp-1))/2;
            }
        }
        cout<<ans<<endl;
        delete [] a;
        m.clear();
    }
    return 0;
}
