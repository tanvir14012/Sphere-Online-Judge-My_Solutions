#include <bits/stdc++.h>
using namespace std;
int ceilIndexBinarySerach(int a[],int left, int right,int key)
{
    int mid;
    while(left+1 < right)
    {
        mid = (left+right)/2;
        if(a[mid] > key)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return right;
}

int main()
{
    cin.sync_with_stdio(false);
    int n,*a,ceil,ans;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            break;
        }
        a = new int[n];
        for(int i = 0; i!= n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        ceil = ans = 0;
        for(int i = 0; i<n-2; i++)
        {
            for(int j = i+1; j<n-1; j++)
            {
                ceil = ceilIndexBinarySerach(a,0,n-1,a[i]+a[j]);
                if(a[i]+a[j]<a[ceil])///making sure that "ceil index" is valid, otherwise it does not exist.
                {
                    ans  += (n-ceil);
                }
            }

        }
        printf("%d\n",ans);
        delete []a;
    }

    return 0;
}
