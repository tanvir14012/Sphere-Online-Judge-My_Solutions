#include <bits/stdc++.h>
using namespace std;

long long unsigned    prime[100000009],a[100000009],n,sqN;
map<long long unsigned  ,long long unsigned  >m;
map<long long unsigned  ,long long unsigned  >::iterator it;
long long unsigned   sieve();
void prime_factorize();
void calculate();
int  main()
{
    long long unsigned   i,t,count;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&n);
        count = sieve();
        cout<<"Total = "<<count<<endl;
        //prime_factorize();
        //calculate();
        m.clear();
        n = 0;
        memset(prime,0,(100000009)*sizeof(long long unsigned ));
    }
    return 0;
}

long long unsigned   sieve()
{
    long long unsigned   count = 0,i,j;
    memset(a,0,(100000009)*sizeof(long long unsigned ));
    sqN = (long long unsigned  ) sqrt(n);
    for(i=3; i<=sqN; i+=2)
    {
        if(a[i/2]==1)
        {
            continue;
        }
        for(j = i*i; j<=n+15; j+=(2*i))
        {
            a[j/2] = 1;
        }
    }
    if(n>=2)
    {
        prime[count++] = 2;
    }
    for(i=3; i<=n+15; i+=2)
    {
        if(a[i/2]==0)
        {
            cout<<i<<endl;
            prime[count++] = i;
        }
    }
    return count-1;
}
void prime_factorize()
{
    long long unsigned   i,n1 = n;
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


void calculate()
{
    long long unsigned   a[m.size()+1],ans = 0,sum,p=0;
    memset(a,0,8*m.size()+8);
    //cout<<m.size()<<endl;
    for( it = m.begin(); it!=m.end(); it++)
    {
        it->second += 1;
        //cout<<it->first<<" :"<<it->second<<endl;
    }
    while(a[m.size()] == 0)
    {
        sum = 1;
        for(long long unsigned  i=0; i<m.size(); i++)
        {
            //cout<<a[i]<<" ";
            it  = m.begin();
            advance(it,i);
            sum *= pow((*it).first,a[i]);
        }
        //cout<<sum<<endl;
        ans+=sum;
        a[0]++;
        it = m.begin();
        advance(it,p);
        while(a[p] == (*it).second)
        {
            a[p] = 0;
            ++p;
            a[p]++;
            advance(it,1);
            if(a[p] != (*it).second)
            {
                p = 0;
            }
        }
    }
    ans-=n;
    printf("Ans = %llu\n",ans);
}
