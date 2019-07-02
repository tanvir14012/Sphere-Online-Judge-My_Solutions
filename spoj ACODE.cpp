#include <bits/stdc++.h>
using namespace std;

long long int dp(int a[],int n);

int main()
{
    char str[5001];
    int n,i;
    while(scanf("%s",&str) != EOF)
    {
        if(str[0] == '0')
        {
            break ;
        }
        n = strlen(str);
        int a[n];
        for( i = 0; i<n ; i++ )
        {
            if(str[i] == '0')
            {
                i-=2;
                break ;
            }
            a[i] = str[i] - 48;
        }
        long long int ans = dp(a,i);
        //cout<<"_______"<<i-1<<endl;
        printf("%lld\n",ans);
    }

    return 0;
}
long long int dp(int a[],int n)
{
    if(n<2)
    {
        return 1;
    }
    long long int temp[n];
    temp[0] = 1;
    if(a[1] + 10*a[0] <=26)
    {
        temp[1] = 2;
    }
    else
    {
        temp[1] = 1;
    }
    for(int i = 2; i<n; i++)
    {
        if(a[i] + 10*a[i-1] <= 26)
        {
            temp[i] = temp[i-1] + temp[i-2];
        }
        else
        {
            temp[i] = temp[i-1];
        }
    }
    return temp[n-1];
}
