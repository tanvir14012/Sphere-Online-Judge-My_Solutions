#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        int a[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        cin>>n;
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int j=0,k=0,mini=INT_MAX;
        sort(a,a+m);
        sort(b,b+n);
        while(j<m && k<n)
        {
            if(a[j]<b[k])
            {
                int temp=b[k]-a[j];
                if(temp<mini)
                {
                    mini=temp;
                }
                j++;
            }
            else
            {
                int temp=a[j]-b[k];
                if(temp<mini)
                {
                    mini=temp;
                }
                k++;
            }
        }
        cout<<mini<<endl;

    }
    return 0;
}
