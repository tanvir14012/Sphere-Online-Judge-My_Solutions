#include <bits/stdc++.h>
using namespace std;

long long unsigned f(int n)
{
    if(n==1)
    {
        return 2;
    }
    else
    {
        return (3*f(n-1))+2;
    }
}
void TOH(int n,int a,int b,int c);
int ct=0;
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        /*
        TOH(n,1,2,3);
        cout<<ct+1<<endl;
        */
        long long unsigned ans=f(n);
        cout<<ans<<endl;
    }
    return 0;
}
/*
void TOH(int n,int a,int b,int c)
{

    if(n==1)
    {
        ++ct;
        return ;
    }
    else
    {
        ++ct;
        TOH(n-1,a,b,c);
        ++ct;
        TOH(n-1,c,b,a);
        ++ct;
        TOH(n-1,a,b,c);
        ++ct;
    }
}*/
/**
Let’s think of this problem in a recursive way. Suppose we know of an algorithm to transfer n-1 discs from peg A to peg C in the shortest number of moves. Now for a configuration of n discs we can use the method we know to:  [Actually this is the algorithm]

1.Transfer the first n-1 discs to peg C
2.Transfer the disc n to peg B
3.Move back n-1 discs to peg A
4.Transfer the disc n to peg C
5.And finally transfer the n-1 discs to peg C again as we did in the first step
Let’s use the notation M_n to denote the number of moves needed to transfer n discs from peg A to peg C. So by the above algorithm, we perform M_{n-1} moves 3 times (steps [1], [3] and [5]) and then perform 2 more moves (steps [2] and [4]). So we can formulate the following recursive equation for the number of steps required to transfer n discs from peg A to peg C:

M_n = 3 * M_{n-1} + 2

There we are! The base is of 0 pegs where we need 0 moves.
**/
