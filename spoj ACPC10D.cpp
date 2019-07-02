#include <bits/stdc++.h>
using namespace std;

long long int  minimum(long long int  a,long long int  b,long long int  c);
int main()
{
    long long int  n;
    while(cin>>n)
    {
        if(n==0)
        {
            break ;
        }
        long long int  a,temp[5],ar[5];

        memset(temp,0,sizeof(long long int)*5);
        memset(ar,0,sizeof(long long int)*5);
        for(long long int  i=0; i<n; i++)
        {
            for(long long int  j=1; j<=3; j++)
            {
                scanf("%d",&a);
                ar[j]=minimum(a+temp[j],a+temp[j-1],a+temp[j+1]);
                cout<<"____"<<ar[j]<<endl;
            }
            memcpy(temp,ar,sizeof(long long int)*5);

        }

        cout<<temp[2]<<endl;

    }
}

long long int  minimum(long long int  a,long long int  b,long long int  c)
{
    cout<<"--------"<<a<<" "<<b<<" "<<c<<endl;
    if(a<=b)
    {
        if(a<=c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else if(b<=c)
    {
        if(b<=a)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
    else if(c<=a)
    {
        if(c<=b)
        {
            return c;
        }
        else
        {
            return b;
        }
    }
}
