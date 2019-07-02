#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,ans,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = n;
        if(n%2 == 0)
        {
            while(n%2 == 0)
            {
                n/=2;
            }
            ans -=(ans/2); /// 2 er jotota multiple ase ta ans theke minus kora.

        }
        for(int i = 3; i*i<=n; i+=2)
        {
            if(n%i == 0)
            {
                while(n%i == 0)
                {
                    n/=i;
                }
                ans -= (ans/i); /// i er sob multiple count, ans theke minus kora
            }
        }
        if(n>1)
        {
            ans -= (ans/n); ///n er sob multiple count, ans theke minus
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**
Prime factors and multiples of prime factors won’t have gcd as 1.
count all prime factors and their multiples and subtract this count from
n to get the totient function value.
let n = 25 = 5 * 5.
n/5 = 5, so 25 has 5 multiples of 5 for which gcd(25,those multiples)!=1.
so, ans = ans - ans/5 = 25 -5 = 20.
they are (1,5,10,15,20).
if(a|b) then say b/a = n. so,there are n-1 multiples of a, from a to b. They are:
    a, a+b, a+2b, ....,a+nb.
**/
