#include <bits/stdc++.h>
using namespace std;
#define sqN 1194967296
long long unsigned prime_list[100000000];/// long long unsigned na dile bipod
bool prime[sqN/2];

void Sieve()
{
    long long unsigned count = 1,sqn = (long long unsigned)sqrt(sqN);
    for(long long unsigned i = 3; i<= sqn; i+=2)
    {
        if(prime[i/2] == false)
        {
            for(long long unsigned j = i*i; j<= sqN; j+=(2*i))
            {
                prime[j/2] = true;
            }
        }
    }
    prime_list[0] = 2;
    for(long long unsigned i = 3; i<=sqN; i+=2)
    {
        if(prime[i/2] == false)
        {
            prime_list[count++] = i;
        }
    }
    cout<<count<<endl;

}
void factorize(long long unsigned n)
{
    if(n == 1)
    {
        cout<<endl;
        return ;
    }
    map<long long unsigned,long long unsigned>m; /// long long unsigned na dile bipod
    long long unsigned i = 0,sqn = (long long unsigned) sqrt(n);
    while(prime_list[i]<= sqn)
    {
        if((n%prime_list[i]) == 0)
        {
            while((n % prime_list[i]) == 0 )
            {
                m[prime_list[i]]++;
                n /= prime_list[i];
            }
        }
        i++;
    }
    if(n>1)
    {
        m[n]++;
    }
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<"^"<<it->second<<" ";
    }
    cout<<endl;
}
int main()
{
    Sieve();
    long long unsigned n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        factorize(n);
    }
    return 0;
}
/**
15 digit number er prime factor বের  করার  জন্য  sqrt(15digit) পর্যন্ত  প্রাইম list বের করলেই enough as b%a=0 means b%(b/a)=0.
sqrt(15digit)<=31622777.
x = 31622777 porjonto prime বের করার jonno sqrt(x) porjonto multiple disacard korlei enough(Sieve of Er..).
n er prime factor <= sqrt(n)
**/

