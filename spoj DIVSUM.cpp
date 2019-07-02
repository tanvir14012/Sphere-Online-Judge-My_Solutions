#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,temp,i;
    long long int count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }
        count = 1;
        temp = (int) sqrt(n);
        for( i=2; i<=temp; i++)
        {
            if(n%i == 0)
            {
                count += i + (n/i);
            }
        }
        ///For corner case
        if(temp*temp == n)
        {
            count -= temp;
        }
        printf("%lld\n",count);
    }
    return 0;
}
/** There is a corner case for perfect square . say :25 = 5 * 5. so, 5 may
be added twice if not handled properly.*/
