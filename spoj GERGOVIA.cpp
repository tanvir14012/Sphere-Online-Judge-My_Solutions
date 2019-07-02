#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag;
    long long int ans;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        int a[n],cumulativeSum[n];
        ans = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>a[i];
        }
        cumulativeSum[0] = a[0];
        for(int i = 1; i<n; i++)
        {
            cumulativeSum[i] = cumulativeSum[i-1] + a[i];
            ans += abs(cumulativeSum[i-1]);
        }

        cout<<ans<<endl;
    }
    return 0;
}


/**
Task:a sequence of overall sum = zero is given. Neutralize the first element completely(make it 0) by moving
towards right and counting work(adjacent elements = 1, more = 2,3...) until it becomes zero. Then do
the second, third .. last. Total work for all = solution.

Solution: Since all elements have to move towards right to be neutralized, a cumulative sum stores
the all intermediate state's value. Absolute Difference between two consecutive  "cumulative sum state"
represents "work", so counting them yields a result.

Since every element is needed to become zero so just keep on accumulating the total work .
Suppose the first element is non-zero then it must be transferred to the next element so whether it
is positive or negative you have to transfer it all. And the work will be absolute value of the
transferred element.
*/
