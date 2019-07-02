#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,temp,l_last,r_last,mx,left,right;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx = left = right = 0;
        l_last= INT_MIN;
        r_last = INT_MAX;
        for(int i = 0; i!=n; i++)
        {
            cin>>temp;
            if(temp>l_last)
            {
                left ++;
                l_last = temp;

            }
            else if(temp<=r_last)
            {
                r_last = temp;
                right = max(left + 1,right+1);
            }
        }
        mx = (left>right)?left:right;
        cout<<mx<<endl;
    }
    return 0;
}
