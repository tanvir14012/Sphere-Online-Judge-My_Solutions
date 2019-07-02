#include <bits/stdc++.h>
using namespace std;
#define mx 1000000
int a[mx],ans[mx];
map<int,bool>m;

void pre_compute()
{
    int count,temp;
    for(int i = 2; i<= 100; i++)
        {
            temp = i*i*i;
            for(int j = temp; j<=mx; j+=temp)
            {
                    m[j] = true;
            }
        }
        count = 1;
        for(int i = 1; i<=mx;i++)
        {
            if(m[i]==false)
            {
                ans[count++] = i;
            }
        }
}
int main()
{
    int t,n,count,an,temp;
    bool flag;
    pre_compute();
    cin>>t;
    for(int c = 1; c<=t; c++)
    {
        cin>>n;
        an= ans[n-1];
        cout<<ans<<endl;
    }
    return 0;
}
