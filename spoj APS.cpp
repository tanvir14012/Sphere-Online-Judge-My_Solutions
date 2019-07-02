#include <bits/stdc++.h>
using namespace std;
#define mx 10000000
#define ll long long

int prime[mx];
ll a[mx];

void solve()
{
    for(int i = 2; i<=mx; i++)
        {
            if(prime[i] == 0)
            {
                prime[i] = i;
                for(int j = i+i; j<=mx; j+=i)
                {
                    if(prime[j] ==0)
                    {
                        prime[j] = i;
                    }
                }
            }
            a[i] = a[i-1] + prime[i];
        }
}
int main()
{
    int t,n;
    solve();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
/**
sol: Summation of smallest prime factor of (from 2 to n).
Like Sieve, prime[i] store the smallest prime factor of i, if(prime[j] ==0) prime[j] = i; stops bigger prime
factor being taken.
Finally, a[i] = a[i-1] + prime[i]; makes the dp solution where a[i] stores the result of i.
a[2] = 2
a[3] = 3 + a[2] = 5
a[4] = 2 + a[3] = 7 (smallest prime factor of 4 is = 2)
a[5] = 5 + a[4] = 12
a[6] = 2 + a[5] = 14
.
.
.
**/
