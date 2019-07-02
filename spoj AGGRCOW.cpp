#include <bits/stdc++.h>
using namespace std;

bool F(long a[],long size,long c,long x);
int main()
{
    long t,n,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        long a[n],start,mid,end,temp;
        for(long i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
        sort(a,a+n);
        start=0;
        end=a[n-1]-a[0]+1;

        while(start+1<end)
        {
            mid=(start+end)/2;
            if(F(a,n,c,mid)==true)
            {
                start=mid;
            }
            else
            {
                end=mid;
            }
        }

        cout<<start<<endl;
    }
    return 0;
}

bool F(long a[],long size,long c,long x)
{
    long ct=1,temp=a[0];
    for(long i=1;i<size;i++)
    {
        if(a[i]-temp >=x)
        {
            ++ct;
            temp=a[i];
        }
        if(ct>=c)
        {
            return true;
        }
    }
    return false;
}
/**
Learned from quora's Raziman T.V>
*/
