#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,ans,sum,left,right;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i = 0; i!=n; i++)
    {
        scanf("%d",&a[i]);
    }
    left = right = sum = ans = 0;

    while(left < n)
    {
        while(right<n && sum + a[right] <= m)
        {
            sum += a[right];
            right++;
        }
        ans = (sum>ans)?sum:ans;
        sum -= a[left];
        left++;
    }
    printf("%d\n",ans);
    return 0;
}
/**
Algorithm:
two pointer left,right initially at the beginning of array.move right forward(r++)
 and extend sum(sum + =a[right]) until sum <= M. It's a sub-array sum i.e.sum<=m,so update
  max. Now decrease sum(sum -= a[left]) and extend left(forward) until sum + a[right] <= m.
  Repeat the algorithm until left reaches the end of array.
  */

  /**
  Officially learned:
  We introduce two pointers l,r denoting startIndex and endIndex of our contiguous
   subarray, with both of them at the tip of the array.
    We now start extending our
   right pointer r provided sum[l,r]<= M Once, we reach at such a stage,
   we don't have any option but to move the left pointer as well and start decreasing
   the sum until we arrive at the situation where we can extend our right pointer again.

   As and when we reach the point, where we need to shift the left pointer, we keep updating
    our maximum sum we have achieved so far.
*/
