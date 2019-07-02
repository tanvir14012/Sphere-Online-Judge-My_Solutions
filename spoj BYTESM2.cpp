#include <bits/stdc++.h>
using namespace std;

long long int mx(long long int a,long long int b);
long long int mx(long long int a,long long int b,long long int c);

int main()
{
    long long int t,r,c;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        long long int temp[c+12],ar[c+12],a=0,ans;
//        for(int i=0; i<c; i++)
//        {
//            temp[i]=0;
//            ar[i]=0;
//        }
        memset(temp,0,(c+12)*sizeof(long long int));
        memset(ar,0,(c+12)*sizeof(long long int));

        for(int i=0; i<r; i++)
        {
            for(int  j=1; j<=c; j++)
            {
                scanf("%lld",&a);

                {
                    ar[j]=a+mx(temp[j],temp[j-1],temp[j+1]);
                }
                //cout<<"___"<<ar[j]<<endl;
            }
//            for(int k=0; k<c; k++)
//            {
//                temp[k]=ar[k];
//            }
            memcpy(temp,ar,(c+12)*sizeof(long long int));
        }
        ans=0;
        for(int i=1; i<=c; i++)
        {
            if(temp[i]>ans)
            {
                ans=temp[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
long long int mx(long long int a,long long int b)
{
    return (a>b)?a:b;
}
long long int mx(long long int a,long long int b,long long int c)
{
    if(a>=b)
    {
        if(a>=c)
        {
            return a;
        }
        return c;
    }
    else if(b>=a)
    {
        if(b>=c)
        {
            return b;
        }
        return c;
    }
    else if(c>=a)
    {
        if(c>=b)
        {
            return c;
        }
        return b;
    }
}
/**
Use a temp array for the current row and update it(you don’t need a h*w matrix), by choosing the maximum sum between the three possible values (left, up, right).
**/
