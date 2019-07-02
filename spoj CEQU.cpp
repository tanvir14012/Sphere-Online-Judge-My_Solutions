#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    int c;
    while(b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int t,a,b,c,GCD;
    scanf("%d",&t);

    for(int i = 1; i<=t; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        GCD = gcd(a,b);
        if(c % GCD == 0)
        {
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": No"<<endl;
        }

    }
    return 0;
}
/**
The simplest linear Diophantine equation takes the form ax + by = c,
where a, b and c are given integers.
This Diophantine equation has a solution (where x and y are integers)
if and only if c is a multiple of the greatest common divisor of a and b.
Moreover, if (x, y) is a solution, then the other solutions have the form
 (x + kv, y − ku), where k is an arbitrary integer, and u and v are the
 quotients of a and b (respectively) by the greatest common divisor of a
 and b.
 */
