#include <bits/stdc++.h>
using namespace std;

long long int a[100002],b[100002];

class BIT
{
private:
    long long int   sz;
public:
    BIT(long long int   sz)
    {
        this->sz = sz;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }
    long long int getSumA(long long int   index)///returns sum(0...index) in original BIT array-a.
    {
        long long int sum = 0;
        while(index > 0)
        {
            sum += a[index];
            index -= (index & (-index));
        }
        return sum;
    }
    long long int getSumB(long long int   index)///returns sum(0...index) in additional BIT array-b.
    {
        long long int sum = 0;
        while(index > 0)
        {
            sum += b[index];
            index -= (index & (-index));
        }
        return sum;
    }
    void update(long long int   index, long long int   val)
    {
        while(index <= sz)
        {
            a[index] += val;
            index += (index & (-index));
        }
    }
    void rangeUpdate(long long int   p,long long int   q,long long int   val)
    {
        update(p,val);
        update(q+1,-val);
        ///updating 2'nd BIT for additional term T.
        long long int   index = p;
        while(index <= sz)
        {
            b[index] += (val * (p-1));
            index += (index & (-index));
        }
        index = q+1;
        while(index <= sz)
        {
            b[index] += (val * (-q));
            index += (index & (-index));
        }
    }
    long long int rangeQuery(long long int   p,long long int   q)
    {
        p--; ///rangeQuery(p,q) = Query(0..q) - Query(0..p-1);
        long long int result_zero_to_p,result_zero_to_q;
        result_zero_to_p = getSumA(p)*p - getSumB(p);
        result_zero_to_q = getSumA(q)*q - getSumB(q);

        return (result_zero_to_q - result_zero_to_p);
    }

};

int main()
{
    long long int   t,n,prompt,mode,p,q,val;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&prompt);
        BIT tree(n);
        for(long long int   i = 1; i<= prompt; i++)
        {
            scanf("%lld",&mode);
            if(mode == 0)
            {
                scanf("%lld%lld%lld",&p,&q,&val);
                tree.rangeUpdate(p,q,val);
            }
            else
            {
                scanf("%lld%lld",&p,&q);
                printf("%lld\n",tree.rangeQuery(p,q));
            }
        }
    }

    return 0;
}
/***
It is BIT range-update + range query problem, learned from topcoder forum, zobayer's
blog,kartik-kujera and all are embedded my programming-practice-khata.
The theorem is excellent !!
*/
