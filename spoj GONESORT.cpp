#include <bits/stdc++.h>
using namespace std;

int a[10000000];
int main()
{
    int t,n,v,mx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx = 1;
    for(int i = 1; i<=n; i++)
    {
        cin>>v;
        if(a[v-1] != 0)
        {
            a[v] = a[v-1] + 1;
            mx = (a[v]>mx)?a[v]:mx;
        }
        else
        {
            a[v] = 1;
        }
    }
    v = n - mx;
    cout<<v<<endl;
    memset(a,0,10000000);
    }
    return 0;
}
/**
Solution = n - LPIS(given list);
LPIS = longest kromic number sequence arki
logic:
you can insert an element only at end or at the begin. you can not insert in middle.
so, LPIS will remain stationary, (n-LPIS length) elements will be moved either
in front or end.
*/
/**
One thing that is not mentioned in the question explicitly: Let's assume a list 10,20,30,40. You must assume there are 40 books in serial 1 2 3 ......40. You are given only 10,20,30,40 to determine how many of them will be moved.
Logic: longest perfect increasing sequence i.e. i,i+1,i+2 ... are never moved. so, n-LPIS length is the solution. Do spoj LPIS first to get it.
so, for 10,20,30,40 , LPIS length = 1(any of them). so 4-1 = 3 is ans.
**/
