#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,temp,x=0,counter=0,*a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        counter=0;
        for(int i=0; i!=n; ++i)
        {
            scanf("%d",&a[i]);
        }
        int i=0,j=0,ct=0;
        for(ct=0; ct<=n; ++ct)
        {
            i=0;
            j=i+ct;
            for(; i<n && j<n; i++,j=i+ct)
            {
                temp=0;
                x=i;
                while(x<=j)
                {
                    //cout<<a[x]<<" ->";
                    temp+=a[x];
                    x++;
                }
                //cout<<endl;
                if(temp==0)
                {
                    counter++;
                }
            }
        }
        printf("%d\n",counter);

    }
    return 0;
}


