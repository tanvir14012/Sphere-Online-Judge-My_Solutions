#include <bits/stdc++.h>
using namespace std;
char str[200];
struct rock
{
    int sweet,total;
};

int dp(int n)
{
    rock M[n+1][n+1];
    int j,temp,sum;
    for(int i = 1; i<=n; i++)
    {
        M[i][i].sweet = M[i][i].total = 0;
    }
    for(int L=2; L<=n; L++)
    {
        for(int i = 1; i<n-L+2; i++)
        {
            j = i+(L-1);
            M[i][j].sweet = M[i][j].total = 0;
            for(int k = i; k<j; k++)
            {
                temp = sum = 0;//temp holds number of 1's. sum holds solution.
                if(i==k && k+1 == j)
                {
                    temp = str[i-1] + str[j-1] - 96;
                    sum = temp;
                }
                else if(i == k)
                {
                    temp = str[i-1] + M[k+1][j].sweet - 48;
                    sum = str[i-1] + M[k+1][j].total - 48;
                    if(temp > ((j-i+1)/2))
                    {
                        sum = j-i+1;
                    }
                }
                else if(k+1 == j)
                {
                    temp = M[i][k].sweet + str[j-1] - 48;
                    sum = M[i][k].total + str[j-1] - 48;
                    if(temp > ((j-i+1)/2))
                    {
                        sum = j-i+1;
                    }
                }
                else
                {
                    temp = M[i][k].sweet + M[k+1][j].sweet;
                    if(temp > (j-i+1)/2)
                    {
                        sum = j-i+1;
                    }
                    else
                    {
                        sum = M[i][k].total + M[k+1][j].total;
                    }
                }
                //cout<<i<<" "<<k<<" "<<k+1<<" "<<j<<"(i,k, k+1,j)"<<endl;
                M[i][j].sweet = max(temp,M[i][j].sweet);
                M[i][j].total = max(sum,M[i][j].total);
            }

        }
    }
    return M[1][n].total;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,str);
        if(n == 1)
        {
            puts(str);
        }
        else
        {
            printf("%d\n",dp(n));
        }
    }
    return 0;
}
/**
M[i][j].sweet = number of 1's in str[i-1,j-1];
M[i][j].total = ans for the sub-problem str[i-1,j-1];
Algorithm: modified matrix chain multiplication.
Note: between str[i,j] there are (j-i+1)elements. so, if number of 1's in
range say x = str[i,j], x>(j-i+1)/2 the all elements of range [i,j] must
be taken i.e.sum = j-i+1 as it satisfies sweet>sour is segment [i,j].
Otherwisw, it is sum of subproblems.
For all combinations of i,k,k+1,j there can be four cases:
1.(i==k)&&(k+1==j) : add [i,j] for both sweet and total.
2.(i==k) :sweet = add(i,dp[k+1,j]),total = dp or if (x=sweet)>(j-i+1)/2 then (j-i+1)
3.(k==j) :same procedure for i==k
4.not any of above.sweet = add(dp[i,k],dp[k+1,j]).sum = dp+dp or (x=sweet)>(j-i+1)/2 then (j-i+1)
Then update dp[i,j] is bigger value found for both sweet and total.
*/
/**
A modified Matrix Chain Multiplication algorithm (MCM) can solve it in O(n^3) using the dynamic programming(dp) approach. The idea is to generate all possible combination of sub-problems and derive a formula that solves the problem in bottom-up manner. Assuming you know the dp solution of MCM, let M[n][n] be a table where M[i,j] stores the solution of elements from i to j in given string. Generate all possible combination of array-index i, j, k i.e. i<=k<j. In the table each range(i to j) can have two properties like:

sweet = number of 1’s in range(i,j)

total = total segments of best choice i.e. sweet>sour.It’s the solution for element(i to j).

dp table can be of type rock like:

struct rock

{

int sweet,total;

};

Now in all possible combination of i, j, k there can be four cases:

1.(i == k) && (k+1 == j)

2. (i == k)

3. (k+1 == j)

4.not any of three above i.e. i, k, k+1, j are distinct.

Main logic: If number of 1’s (sweets) in between element index (i to j) < (total elements in range)/2 , total elements in range is the optimal solution.

otherwise, optimal solution = summation of sub-problems.

Now fitting the logic into the table for all those 4 cases and taking the maximum in each step will yield an optimal solution.
*/
