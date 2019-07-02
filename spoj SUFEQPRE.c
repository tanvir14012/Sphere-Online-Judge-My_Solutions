#include <stdio.h>
#include <string.h>
char s[1000009];
int z[1000009];

int zee()
{
    int n = strlen(s), l = 0, r = 0, k= 0,count = 0,i;
    for(i = 1; i<n; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r<n && s[r-l] == s[r])
            {
                r++;
            }
            r--;
            z[i] = r-l+1;
        }
        else
        {
            k = i-l;
            if(z[k] < r-i+1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while(r<n && s[r-l] == s[r])
                {
                    r++;
                }
                r--;
                z[i] = r-l+1;
            }
        }
        if(z[i] == n-i)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int t,it,i;
    scanf("%d%*c",&t);
    for(i = 1; i <= t; i++)
    {
        gets(s);
        printf("Case %d: %d\n",i,zee());
    }
    return 0;
}
/**

Given a string S of length n, the Z Algorithm produces an array Z where Z[i] is the length of
the longest substring starting from S[i] which is also a prefix of S.

if(Z[i] == n-i) count++; for i = 1 .... n-1.
    ans = count.


**/
