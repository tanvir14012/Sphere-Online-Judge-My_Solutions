#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,k,test=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i!=n; ++i)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    test=k;
    int m=0,mx=0;

    while(k<=n)
    {
        if((((m==0) || (mx==a[m-1]) )) /*&& (k-1)<n */)
    {
        mx=0;
        for(int i=m; i<k; ++i)
        {
            if(a[i]>mx)
            {
                mx=a[i];
            }
        }
        cout<<mx<<" ";
    }
    else if((m>=0 && m<=n-test)&& mx!=a[m-1] /*&& (k-1)<n*/)
    {
        if(a[k-1]>mx)
        {
            mx=a[k-1];
        }
        cout<<mx<<" ";

    }
    // cout<<"k="<<k<<" m="<<m<<endl;
    ++m;
    ++k;

}
return 0;
}
/**
9
1  2  3  1  4  5  2  3  6
3
*/

