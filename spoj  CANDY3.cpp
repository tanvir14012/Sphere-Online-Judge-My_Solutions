#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int temp;
        long long int ans=0;
        for(size_t i=0; i!=n; ++i)
        {
            cin>>temp;
            ans=(ans+temp)%n;/** (a+b)%m=(a%m  + b%m)%m
        }

        if(ans!=0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    //system("pause");
    return 0;
}
