#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,*a1,*a2,i,j,ans,sum_i,sum_j;
    while(scanf("%d",&n1) == 1)
    {
        if(n1 == 0)
        {
            break;
        }
        a1 = new int[n1];
        for(i = 0; i != n1; i++)
        {
            scanf("%d",&a1[i]);
        }
        scanf("%d",&n2);
        a2 = new int[n2];
        for(i = 0; i != n2; i++)
        {
            scanf("%d",&a2[i]);
        }
        i = j = sum_i = sum_j = ans = 0;

        while(i < n1 || j < n2)
        {
            if(i < n1 && j < n2)
            {
                if(a1[i]<a2[j])
                {
                    sum_i += a1[i];
                    i++;
                }
                else if(a1[i]>a2[j])
                {
                    sum_j += a2[j];
                    j++;
                }
                else
                {
                    sum_i += a1[i];
                    i++;
                    sum_j += a2[j];
                    j++;
                    ans += max(sum_i,sum_j);
                    sum_i = sum_j = 0;
                }
            }
            if(i>=n1)
            {
                while(j < n2)
                {
                    sum_j += a2[j];
                    j++;
                }
            }
            if(j>=n2)
            {
                while(i<n1)
                {
                    sum_i += a1[i];
                    i++;
                }
            }

        }
        ans += max(sum_i,sum_j);
        printf("%d\n",ans);
        delete []a1;
        delete []a2;
    }

    return 0;
}
/**
Used merging two sorted array algorithm.

Logic:i is related to a1[],like j with a2[].
1st while loop:iterate until i or j go to end of it's array;
smaller element(a1[i] or a2[j]) is pushed to output array and (i||j)++ i.e.(step forward).
end loop.

2nd and 3rd loop:
if one of i or j reached end,then add elements of uncomplete i or j until end to output array.
As,i reached end, task of a1[] is done.so, put a2[j to end] to output.  **/
