#include <bits/stdc++.h>
using namespace std;

int mixtureDp(int a[],int n)
{
    int M[n+1][n+1],j,temp,sum;
    for(int i = 1; i<=n; i++)
    {
        M[i][i] = 0;
//        if(i+1 <= n)
//        {
//            M[i][i+1] = a[i-1]*a[i];
//        }
    }
    for(int L = 2; L<=n; L++)///matrix mult er moto 1 length kom nah.
    {
        for(int i = 1; i<n-L+2; i++)
        {
            j = i+(L-1);
            M[i][j] = INT_MAX;
            for(int k = i; k<j; k++)
            {
                sum = 0;
                if(i == k)
                {
                    for(int it = k; it<j; it++)
                    {
                        sum += a[it];
                    }
                    sum %= 100;
                    temp = a[i-1] * sum;

                }
                else if(k+1 == j)
                {
                    for(int it = i-1; it<k; it++)
                    {
                        sum += a[it];
                    }
                    sum %= 100;
                    temp = a[j-1]*sum;
                }
                else
                {
                    int sum1 = 0;
                    for(int it = i-1; it<k; it++)
                    {
                        sum += a[it];
                    }
                    sum %= 100;
                    for(int it = k; it<j; it++)
                    {
                        sum1 += a[it];
                    }
                    sum1 %= 100;
                    temp = sum*sum1;
                }
                temp += M[i][k]+M[k+1][j];
                if(temp<M[i][j])
                {
                    M[i][j] = temp;
                }
            }
        }
    }
//    for(int i = 1; i<=n; i++)
//    {
//        for(int j = 1;j<=n; j++)
//        {
//            if(j>i) cout<<setw(5)<<M[i][j]<<" ";
//            else cout<<"--x--"<<" ";
//        }
//        cout<<endl;
//    }
    return M[1][n];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(int i = 0; i!=n; i++)
        {
            scanf("%d",&a[i]);
        }
        if(n<3)
        {
            if(n==1)
            {
                printf("%d\n",0);
            }
            else if(n==2)
            {
                printf("%d\n",a[0]*a[1]);
            }
        }
        else
        {
            int ans = mixtureDp(a,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/**
Algorithm: a bit modified matrix chain multiplication.
formula: M[i,j] = M[i,k] + M[k+1,j]+ temp ;
where , if(i == k) then temp = sum{k+1,to, j} = sum(a[k+1-1]+..+a[j-1]) as index starts at zero.
else if(k+1 ==j) then temp = sum(a[i-1]+..+a[k-1])
else temp = sum(a[k+1-1]+..+a[j-1])%100  *  sum(a[i-1]+..+a[k-1])%100.
**/
/**
my comment:
It is a modified matrix chain multiplication(MCM) problem.
First learn MCM algorithm from a video(like: youtube, Tusher Roy's…) and practice it in pen-paper(perfectly). Then try to implement it by yourself(you must consider matrix-length in your loops. Then see the dp(dynamic programming) solution of a reference like:geeks for geeks and refine it if you did any mistake.
Now try to discover the formula of this problem. Stop reading further ...(do all these above). This problem need length L upto <=n;
formula, I discovered: M[i,j] = Minimum{M[i,k] + M[k+1,j]+ temp} ;i<=k<j

where , if(i == k) then temp = (sum{k+1,to, j} = sum(a[k+1-1]+..+a[j-1]))%100 * a[i-1]. as index starts at zero.
else if(k+1 ==j) then temp = sum(a[i-1]+..+a[k-1]) %100 * a[j-1].

else temp = sum(a[k+1-1]+..+a[j-1])%100 * (sum(a[i-1]+..+a[k-1])%100).

Note that: a[] is input and M[n+1][n+1] is a dp bottom-up table. index starts from 0 in a[] but in M[][] it starts from 1 because of the MCM formula(a[i-1] is used).
**/
