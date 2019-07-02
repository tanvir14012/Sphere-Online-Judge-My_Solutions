#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    long long int a,temp,cur,prev;
    cin>>t;
    for(int it = 1; it<= t; it++)
    {
        temp = cur = prev = 0;
        cin>>n;
        for(int i = 0; i<n; i++)
        {
            cin>>a;
            temp = cur;
            cur =max(cur,a + prev);
            prev = temp;
        }
        cout<<"Case "<<it<<": "<<max(cur,prev)<<endl;
    }
    return 0;
}
