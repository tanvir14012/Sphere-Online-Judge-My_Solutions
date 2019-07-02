#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L;
    double d;
    while(cin>>L)
    {
        if(L==0)
        {
            break ;
        }
        d=(L*L)*(1.0/(2.0*3.1415926));
        printf("%.2lf\n",d);

    }
    return 0;
}
/**
Fact:
    প্রশ্নে L হল length যেটা পরিধি/2 ।
    অর্ধ-circle হলেই কেবল area maximum hote pare.
    L=(2*pi*r)/2=pi*r.
    so,r=L/pi;
    ans=(pi*r*r)/2 , as  অর্ধ-circle.
    so, ans={pi* (L/pi) * (L/pi) }/2
           =L^2 /(2*pi).

           **/
