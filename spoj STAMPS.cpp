#include <bits/stdc++.h>
using namespace std;

bool cp(int a,int b)
{
    if(a>b)
    {
        return true;
    }
    return false;
}
int main()
{
    int t,n,num;
    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        scanf("%d%d",&num,&n);
        int a[n],sum,counter;
        for(int i=0;i!=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cp);
        sum=counter=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            ++counter;
            if(sum>=num)
            {
                break;
            }
        }
        if(sum>=num)
        {
            cout<<"Scenario #"<<it<<":\n";
            cout<<counter<<endl<<endl;
        }
        else
        {
            cout<<"Scenario #"<<it<<":\n";
            cout<<"impossible"<<endl<<endl;
        }
    }
    return 0;
}
