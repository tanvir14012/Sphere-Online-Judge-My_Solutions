#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long unsigned n;
    long double temp;
    cin>>n;
    temp=log2(n);
    temp=temp-(long long unsigned)temp;
    if(temp==0.0000)
    //if((n & (n-1))==0) /** i.e. power of 2 **/
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }
    return 0;
}
/**
power of 2 হলেই  কেবল  কমতে কমতে ০ হবে।   অন্যথায়
as for n=odd, n=3*n+3 is even, কিন্ত  এটা  infinty hobe.

akbar n1=n/2=odd holo, tappor oita*3+3 > n1 hobe . . . .. .. . ..
**/
