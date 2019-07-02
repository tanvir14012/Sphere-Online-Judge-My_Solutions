#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long int ans;
    while(cin>>n)
    {
        if(n==0)
        {
            break ;
        }
        ans = n*(n+1)*(2*n+1)/6;
        cout<<ans<<endl;
    }
    return 0;
}
/**
If n = 1, there is one 1-by-1 square.

           If n = 2, there is one 2-by-2 square and four 1-by-1 squares.

           If n = 3, there is one 3-by-3 square, four 2-by-2 squares and nine 1-by-1 squares.

           If we continued the above sequence for an arbitrary n, then we would have one n-by-n square, four (n - 1)-by-(n - 1) squares,
            nine (n - 2)-by-(n - 2) squares,16 (n-3) by (n-3) squares ... , and (n*n) 1-by-1 squares.

           Notice that this is just the summation: n*(n+1)*(2*n+1)/6.

*/
