#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,ans;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        ans=(int)log2(n);
        cout<<ans<<endl;
    }

    return 0;
}
/**
Math logic:
Any number up to (2^n)-1 can be represented by the combinations of the ‘n’ numbers: 20,21,22,...2n-1.
For example, if 7 is considered, all numbers from 1 to 7 can be represented as combinations of 1,2, and 4:
1 = 1; 2 = 2; 3 = 1+2; 4 = 4; 5 = 1+4; 6 = 2+4; 7 = 1+2+4


If 9 is considered, all numbers from 1 to 9 can be represented as combinations of 1,2,4 and 2:
1 = 1; 2 = 2; 3 = 1+2; 4 = 4; 5 = 1+4; 6 = 2+4; 7 = 1+2+4; 8 = 2+2+4; 9 = 1+2+2+4;

If 15 is considered, all numbers from 1 to 15 can be represented as combinations of 1,2,4 and 8:
1 = 1; 2 = 2; 3 = 1+2; 4 = 4; 5 = 1+4; 6 = 2+4; 7 = 1+2+4; 8 = 8; 9 = 1+8; 10 = 2+8;
11 = 1+2+8; 12 = 4+8; 13 = 1+4+8; 14 = 2+4+8; 15 = 1+2+4+8
**/
