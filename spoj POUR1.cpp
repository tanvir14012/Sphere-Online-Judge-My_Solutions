#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b !=0 )
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int pour(int a, int b, int c, int x, int y)
{
    //x=capacity of a, y = capacity of b
    int count = 0;
    while(a != c && b != c)
    {
        if(a == 0)
        {
            a = x;
        }
        else if(b == y)
        {
            b = 0;
        }
        else
        {
            b = b+a;
            a = 0;
            if(b > y)
            {
                a = b-y;
                b = y;
            }
        }
        count ++;
        //cout<<a<<" "<<b<<endl;///steps
    }
    return count;
}
int main()
{
    int t,a,b,c,gcd_ab,a_first,b_first,ans;
    cin>>t;
    while(t--)
    {

        cin>>a>>b>>c;
        gcd_ab = gcd(a,b);
        if(c % gcd_ab != 0 || (c>a && c>b))
        {
            cout<<-1<<endl;
        }
        else
        {
            a_first = pour(0,0,c,a,b);
            b_first = pour(0,0,c,b,a);
            ans = (a_first<b_first)? a_first : b_first;
            cout<<ans<<endl;
        }
    }
    return 0;
}
/**
Problem: You are at the side of a river. You have a "a" liter jug and a "b" liter jug. The jugs do not have markings to allow measuring smaller quantities. How canyou use the jugs to measure "c" liter of water?

Representing the problem in equation: ax + by = c where

x = number of time one jug is poured/discharged(+ve/-ve)

y = number of time the other jug is poured/discharged(+ve/-ve)

Theorem. The Diophantine equation ax+by = c is solvable

if and only if gcd(a, b) divides c.

Corner case :c must satisfy: c <= max(a,b)

Simulation:

You must simulate by doing "pouring action" only in one jug and "discharging action" only in the opposite jug.

(1)pour in a, discharge in b: if a is empty pour a full, if b is full the discharge and make b empty. Otherwise, transfer water from a to b. Each of those three condition is a step & can happen only once at a time.

(2)pour in b, discharge in a: if b is empty pour it full, if a is full make it empty. Otherwise, transfer water from b to a.

count total steps for (1) and (2), the minimum is the answer.
**/
