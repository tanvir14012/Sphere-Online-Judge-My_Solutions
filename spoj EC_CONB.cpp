#include <bits/stdc++.h>
using namespace std;

void convert_binary(unsigned long long *p);
int main()
{
    unsigned long long  n,temp=0,r,sum=0,k;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        if((temp&1)==0)
        {
            int a[120];
            int i=0;
            while(temp)
            {
                r=temp%2;
                a[i++]=r;
                temp/=2;
            }
            k=0;
            while(i--)
            {
                sum+=a[i]*((long long unsigned)pow(2,k));
                k++;
            }
            cout<<sum<<endl;
            sum=0;

    }
    else
    {
        cout<<temp<<endl;
    }
    }

    return 0;
}


