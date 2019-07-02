#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,p;
    while(cin>>a>>b>>c)
    {
        if(a==0 && b==0 && c==0)
        {
            break ;
        }
        d=b-a;
        p=b+d;
        if(c==p)
        {
            cout<<"AP "<<(c+d)<<endl;
        }
        else
        {
            d=(b/a);
            cout<<"GP "<<(c*d)<<endl;
        }
    }
    return 0;
}
