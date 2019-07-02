#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int a1,a3,al3,sum,d,temp,n;
        cin>>a3>>al3>>sum;
        n=(2*sum)/(a3+al3);
        d=(al3-a3)/(n-3+1-3);
        a1=a3-2*d;
        cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
            temp=a1+i*d;
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/** Arithmetic progression has the property that
a1 + an = a2 + an-1 = ... = ak + a_n-k+1
Sum = n/2(a1+an) = ... = n/2(ak = a_n-k+1).
also, a_n = a_m + (n-m)d
**/
/**
sum=(n/2)(a1+an)=(n/2)(a3+al3)
a(n)=a(m)+(n-m)*d;where n and m are any'th pod i.e. n>m;
derive d from ^.
a1=a3-2*d
}
**/
