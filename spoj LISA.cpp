#include <bits/stdc++.h>
using namespace std;

char str[100],op[100];
int a[100];

int calculate(int a,int b,char op)
{
    int ans;
    switch(op)
    {
    case '+':
        ans = a+b;
        break;
    case '*':
        ans = a*b;
        break;
    default:
        ans = 0;
        break;
    }
    return ans;
}
int minimumValueDp(int x)
{
    int j,M[x+1][x+1],temp;
    for(int i = 1; i<=x; i++)
    {
        M[i][i] = 0;
    }
    for(int L = 2; L<=x; L++)
    {
        for(int i = 1; i<x-L+2; i++)
        {
            j = i + (L - 1);
            M[i][j] = INT_MAX;

            for(int k = i; k<j; k++)
            {
                //cout<<"i k k+1 j = "<<i<<" "<<k<<" , "<<k+1<<" "<<j<<endl;

                if(i == k && k+1 == j)
                {
                    temp = calculate(a[i-1],a[j-1],op[i-1]);
                }
                else if(i == k)
                {
                    temp = calculate(a[i-1],M[k+1][j],op[i-1]);
                }
                else if(k+1 == j)
                {
                    temp = calculate(M[i][k],a[j-1],op[k-1]);
                }
                else
                {
                    temp = calculate(M[i][k],M[k+1][j],op[k-1]);
                }
                if(M[i][j]>temp)
                {
                    M[i][j] = temp;
                }
            }
        }
    }
//    for(int i = 1; i<=x; i++)
//    {
//        for(int j  = 1; j<=x; j++)
//        {
//            if(j>i) cout<<M[i][j]<<" ";
//            else cout<<"--x--";
//        }
//        cout<<endl;
//    }
    return M[1][x];
}
int maximumValueDp(int x)
{
    int j,M[x+1][x+1],temp;
    for(int i = 1; i<=x; i++)
    {
        M[i][i] = 0;
    }
    for(int L = 2; L<=x; L++)
    {
        for(int i = 1; i<x-L+2; i++)
        {
            j = i + (L - 1);
            M[i][j] = 0;

            for(int k = i; k<j; k++)
            {
                //cout<<"i k k+1 j = "<<i<<" "<<k<<" , "<<k+1<<" "<<j<<endl;

                if(i == k && k+1 == j)
                {
                    temp = calculate(a[i-1],a[j-1],op[i-1]);
                }
                else if(i == k)
                {
                    temp = calculate(a[i-1],M[k+1][j],op[i-1]);
                }
                else if(k+1 == j)
                {
                    temp = calculate(M[i][k],a[j-1],op[k-1]);
                }
                else
                {
                    temp = calculate(M[i][k],M[k+1][j],op[k-1]);
                }
                if(M[i][j]<temp)
                {
                    M[i][j] = temp;
                }
            }
        }
    }
//    for(int i = 1; i<=x; i++)
//    {
//        for(int j  = 1; j<=x; j++)
//        {
//            if(j>i) cout<<M[i][j]<<" ";
//            else cout<<"--x--";
//        }
//        cout<<endl;
//    }
    return M[1][x];
}
int main()
{
    int n,x,y,mx,mn;

    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%s",str);
            x = y = 0;
            for(int  i= 0; i<strlen(str); i++)
            {
                if(isdigit(str[i]))
                {
                    a[x++] = str[i]-'0';
                }
                else
                {
                    op[y++]=str[i];
                }
            }
            if(y==0)
            {
                cout<<str<<" "<<str<<endl;
            }
            else
            {
                mn = minimumValueDp(x);
                mx = maximumValueDp(x);
                cout<<mx<<" "<<mn<<endl;
            }
            memset(a,0,100*sizeof(int));
        }
    }
    return 0;
}
/***
self-discovered, without any tutorial except MCM.
4 ta case handle korte hoise. M[][] array ti bottom-up table.formula gula ber korta onek
pain hoice + hard to find bug debugging.
loop gula matrix chain mult. er moto.
dependency gula loop er vetor i,k,k+1,j print kore ber kora effective.
a[i] and a[i+1] er operator  = op[i].

**/
