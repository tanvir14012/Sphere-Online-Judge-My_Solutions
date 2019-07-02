#include <bits/stdc++.h>
using namespace std;
int  T[2][2000001];
inline int Max(int a,int b)
{
    return (a>b)?a:b;
}
int dp(int n, int KC, int w[],int v[]);
int main()
{
    int n,KC,ans;
    //cout<<"Enter  Knapsack capacity(KC) and Number of items(n)"<<endl;
    cin>>KC>>n;
    int v[n],w[n];
    //cout<<"Enter weight and value of all items"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>v[i]>>w[i];
    }
    ans = dp(n,KC,w,v);
    //cout<<"Maximum value = ";
    cout<<ans<<endl;
    return 0;
}

int dp(int n, int KC, int w[],int v[])
{
    for(int i = 0; i<=KC; i++)
    {
        if(w[0] <= i)
        {
            T[0][i] = v[0];
        }
        else
        {
            T[0][i] = 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        i%=2;
        for(int j=0; j<=KC; j++)
        {
            if(w[i] <= j)
            {
                T[i][j] = Max(v[i]+T[i-1][j-w[i]],T[i-1][j]);
            }
            else
            {
                T[i][j] =  T[i-1][j];
            }
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=KC;j++)
        {
            cout<<setw(2)<<T[i][j]<<"  ";
        }
        cout<<endl;
    }
    */
    return T[n][KC];
}


/*
5 10
2 3
2 5
1 4
2 6
3 4
4 5
7 8
6 9
5 8
4 5
*/
/**
5 4
4 6
3 4
2 9
5 5
**/

