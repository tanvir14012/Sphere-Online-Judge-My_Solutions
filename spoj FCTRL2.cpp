#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d,carry,t,z;
        cin>>n;
        double p=0.0;
        for(int i=2; i<=n; i++)
        {
            p+=log10(i);
        }
        d=(int) p+1;
        //cout<<"Digits of "<<n<<"! = "<<d<<endl;
        int *a=new int[d];
        memset(a,0,d*sizeof(int));
        a[0]=1;
        p=0.0;
        for(int i=2; i<=n; i++)
        {
            p+=log10(i);
            z=(int)p+1;
            carry=0;
            for(int j=0; j<z; j++)
            {
                t=(a[j]*i)+carry;
                a[j]=t%10;
                carry=t/10;
            }
        }
        for(int i=d-1; i>=0; i--)
        {
            cout<<a[i];
        }
        cout<<endl;
        delete []a;
    }
    return 0;
}

