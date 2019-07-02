#include <bits/stdc++.h>
using namespace std;
#define L long long int
int main()
{
    int n,n1;
    while(cin>>n1)
    {
        if(n1==-1)
        {
            break ;
        }
        n=n1;
        n=(n-1)/6;
        n*=2;
        L i,ans;
        i=((int)(sqrt(1+4*n)) - 1)/2;

        ans=((i*(i+1))/2)*6 +1;
        if(ans==n1)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }
    }
    return 0;
}
/**
number=1+6*(1+2+...+i)
number=1+6*(i*(i+1)/2)
i^2 + i =do
i=do.
see if i match with given number
**/
