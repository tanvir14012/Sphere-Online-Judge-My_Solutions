#include <stdio.h>
#include <math.h>

int main()
{
    int t, count;
    long long int n, odd, even , temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        temp = n;
        count = 0;
        if(n == 0)
        {
            printf("0 1\n");
        }
        else
        {
            while(n != 0)
            {
                if(n & 1)
                {
                    count ++;
                }
                n = n >> 1;
            }
            n = pow(2, count);
            odd = n;
            even = temp+1-n; //total (n+1) : nc0...ncn.
            printf("%lld %lld",even, odd);
        }
    }
    return 0;
}
/**
Even => ncr % 2 == 0, odd => ncr % 2 == 1.
2 is prime, so in Lucas theorem : ncr%2 = ((n0/r0)...(nk/rk))%2.
so, binary n0n1...nk is common in all nc0..ncn.
To find whether nCr is odd or even we use the Lucas theorem. It is :
(588 C 277) % 5 = ?
                Representation of 588 in base of 5 = 4323
                Representation of 277 in base of 5 = 2102
                Now your answer reduces to = ((4 choose 2)(3 choose 1)(2 choose 0)(3 choose 2)) % 5
                                         = (6 * 3 * 1 * 3) % 5
                                         = 54 % 5
                                         = 4
Lucas theorem states that nCr % m, where, m is a prime number = (n0 C r0 % m) * (n1 C r1 % m)*........
(nk C rk % m), where n<0n1...nk and r0r1...rk are the representation of n and r in base m respectively. Hence, in base 2 representation, the digits will be either 0 or 1.
So,according to lucas theorem,  nCr % 2 will give us the cases 1C1, 1C0, 0C0, 0C1. Now, 0C1  = 0. Hence, if nCr has the case 0C1 then its always even else odd.

Now for counting the number of odd terms we count the number of 1's in n' s binary representation. We can assign either 0 or 1 to the 1's of n in nCr. Hence, number off odd terms = 2^(no of 1's).
Here,
nC0....nCn : total (n+1) numbers;
In Lucas theorem , binary representation n  is common for all (n+1) numbers as numerators.
0c0 = 1, 0c1 = 0, 1c1=1, 1c0 = 1.Only 0C1 = 0.
0*anything = 0, so number of 0's in n will make some nCr even, regardless of other co-efficient of the nCr.
Say, number of 0's in n = t, t will affect some number of nc0..nCr...ncn , making them even, but as 0C0 = 1,it's not 2^t,so,we can not calculate directly.
now, let number of 1's in n = f, as (1 C 0or1) = 1, f will make exactly 2^f numbers from nc0...ncn odd.
How pattern of binary numbers from 0...n allow 2^f number to be odd, I dont know.
**/
