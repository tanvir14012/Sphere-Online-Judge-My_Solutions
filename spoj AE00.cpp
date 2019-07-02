#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
    int x,ans=0,ct=0;
    x=(int)sqrt(n);
    for(int i=1; i<=x; ++i)
    {
        ans+=(n/i)-ct;
        //cout<<ans<<"  ";
        ++ct;
    }
    cout<<ans<<endl;
    }
    return 0;
}
/**
input:6
1 ta, 2 ta ----- 6 ta=6
1 ta 3*3
1 ta 2*2
total=8

**/
