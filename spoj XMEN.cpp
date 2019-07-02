#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int t,n,mx,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx = 1;
        for(int i = 0; i<n; i++)
        {
           cin>>temp;
           a[temp] = -1;
        }
        for(int i = 0; i<n; i++)
        {
           cin>>temp;
           if(a[temp-1] != 0)
           {
               a[temp] = a[temp-1]+1;
               mx = (a[temp]>mx)?a[temp]:mx;
           }
        }
        cout<<mx<<endl;
        memset(a,0,100000);
    }
    return 0;
}
