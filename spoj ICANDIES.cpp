#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n%3==0)
        {
            n-=5;
        }
        while(n%3 !=0)
        {
            n-=5;
        }
        if(n <= 0)
        {
            cout<<"Case "<<i<<": "<<-1<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": "<<n<<endl;
        }

    }

    return 0;
}

