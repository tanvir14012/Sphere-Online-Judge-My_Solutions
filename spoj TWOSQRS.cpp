#include <bits/stdc++.h>
using namespace std;

long long int     prime[10000090],n,sqN;
bool a[10000100];
map<long long int   ,long long int   >m;
map<long long int   ,long long int   >::iterator it;
long long int    sieve();
void prime_factorize();
void decide();

int  main()
{
    long long int    i,t,count;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        count = sieve();
        //cout<<"Total = "<<count<<endl;
        prime_factorize();
        decide();
        m.clear();
        n = 0;
        memset(prime,0,(1000000)*sizeof(long long int  ));
    }
    return 0;
}
long long int    sieve()
{
    long long int    count = 0,i,j;
    memset(a,0,(1000000)*sizeof(bool));
    sqN = (long long int   ) sqrt(n);
    for(i=3; i<=sqN; i+=2)
    {
        if(a[i/2]==1)
        {
            continue;
        }
        for(j = i*i; j<=sqN + 10; j+=(2*i))
        {
            a[j/2] = 1;
        }
    }
    if(n>=2)
    {
        prime[count++] = 2;
    }
    for(i=3; i<=sqN + 100; i+=2)
    {
        if(a[i/2]==0)
        {
            //cout<<i<<endl;
            prime[count++] = i;
        }
    }
    return count-1;
}
void prime_factorize()
{
    long long int    i,n1 = n;
    for(i = 0; prime[i] <= sqN; i++)
    {
        if(n1%prime[i] == 0)
        {
            while(n1%prime[i] == 0)
            {
                m[prime[i]]++;
                n1/=prime[i];
            }
        }
    }
    if(n1 > 1)
    {
        m[n1]++;
    }
}

void decide()
{
    bool flag = true;
    for(it = m.begin();it!=m.end(); it++)
    {
        if((it->first - 3)%4 == 0)
        {
            if(it->second % 2 !=0 )
            {
                flag = false;
                break ;
            }
        }
    }
    if(flag)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

/**
Theorem 1.1 A number n is a sum of two squares if and only if all prime factors of n of
the form 4m+3 have even exponent in the prime factorization of n.
I need to generate prime upto sqrt(n),it will get the job done.
*/

