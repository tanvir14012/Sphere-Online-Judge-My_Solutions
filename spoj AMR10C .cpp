#include <bits/stdc++.h>
using namespace std;
int v[100000];
void sieve(int n,int v[]);
void primefactors(int n,int v[]);
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        sieve(n,v);

        primefactors(n,v);
    //cout<<"Prime factors:"<<endl;
//    for(auto it=f.begin(); it!=f.end(); it++)
//    {
//        cout<<*it<<" ,";
//    }cout<<endl;
    }
    return 0;
}
void sieve(int n,int v[])
{
    int a[(n>>1)+1];
    memset(a,0,((n>>1)+1)*sizeof(int));

    int sqN=(int )sqrt(n);
    for(int i=3; i<=sqN; i+=2)
    {
        if(a[i>>1]==1)
        {
            continue;
        }
        for(int j=i*i; j<=n; j+=(i*2))
        {
            a[j>>1]=1;
        }
    }
    v[0]=2;
    int p=1;
    for(int i=3; i<=n; i+=2)
    {
        if(a[i>>1]==0)
        {
             v[p++]=i;///mistake prone:push i,not a[i>>1]
        }
    }
    //cout<<"Total primes = "<<v.size()<<endl;
    return ;
}

void primefactors(int n,int v[])
{
    int sqN=(int) sqrt(n);
    int count=0,ans=0;
    for(int i=0; v[i]<=sqN; i++)
    {
        if(n%v[i]==0)
        {
            count=0;
            while((n%v[i])==0)
            {
                count++;
                //f.push_back(v[i]);
                n/=v[i];
            }
        }
        sqN=(int)sqrt(n);
        ans=max(ans,count);
    }
//    if(n>1)
//    {
//        f.push_back(n);
//    }
    ans=max(1,ans);
    printf("%d\n",ans);
    return;
}

