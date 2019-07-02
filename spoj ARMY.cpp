#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[m],b[n],i,j;
        for(int i=0;i<m;i++)
        {
            //cin>>a[i];
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            //cin>>b[i];
        }

        sort(a,a+m);
        sort(b,b+n);

        i=m-1;
        j=n-1;
        while(i>=0 && j>=0)
        {
            if(a[i]>=b[j])
            {
                j--;
            }
            else if(a[i]<b[j])
            {
                i--;
            }
        }
        if(i>j)
        {
            cout<<"Godzilla"<<endl;
        }
        else if(i<j)
        {
            cout<<"MechaGodzilla"<<endl;
        }
        else
        {
            cout<<"uncertain"<<endl;
        }
    }
    return 0;
}
