#include <bits/stdc++.h>
using namespace std;

const int MX = 100002;
const int MOD = 5000000;
int BIT[52][MX];

void  update(int *bit,int index,int val)
{
    while(index < MX)
    {
        bit[index] += val;
        if(bit[index] >= MOD)
        {
            bit[index] -= MOD;
        }
        index += (index & (-index));
    }
}
int  query(int *bit,int index)
{
    int sum = 0;
    while(index > 0) //BIT starts from 1
    {
        sum += bit[index];
        if(sum >= MOD)
        {
            sum -=  MOD;
        }
        index -= (index & (-index));
    }
    return sum;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a;
    for(int i  = 0; i<n; i++)
    {
        scanf("%d",&a);

        update(BIT[1],a+1,1);/**BASE CASE*///BIT starts from 1, a could be 0, so.
            for(int ki = 2; ki <= k; ki++)
            {
            update(BIT[ki], a+1, query(BIT[ki - 1],a));///Recurrence, column by column
            }
    }
    printf("%d\n",query(BIT[k],100001));
    return 0;
}

/**
শালা প্রচুর জালাইছে ।  MX,MOD এগুলা const variable e না রেখে  direct বসানোর কারনে wa,tle
পেঁড়া ।

এখানে array element এর value range কম  তাই তাদেরকে BIT তে index হিসেবে use kora গেছে ,
নাইলে Hashing, Normalising etc. লাগত ।

Soln:
Let, A[i][j] = j length  এর  Increasing Subsequence(IS), IS টার  j'th বা
সর্বশেষ  element এর  index = i, বাকী (j-1) element গুলা থাকতে পারে (0 ... থেকে  i-1) index
এর মাঝে ।

তাহলে, Soln = A[n][k] + A[n-1][k] + A[n-3][k] + ..... + A[k][k].

A[i][j] যেভাবে পাবঃ
লক্ষণীয়, A[any index][1] = 1. [Base Case]
A[i][j] = A[i-1][j-1] + A[i-2][j-1] + A[i-3][j-1] + ... + A[j-1][j-1]

Implementation **:

Let, BIT[52][100002] where BIT[k][value] = 2D BIT table টার (k-1) তম row
এ value এর চেয়ে ছোট মোট কয়টা আছে , কিন্ত inupt এ value এর পরে যেসব element এসেছে
সেগুলো  consider করা যাবে না ।

Base Case : BIT[1][any value] = 1.
Base Case এর সাহায্যে  table টা column by colmumn পুরন করলে (মানে সর্বপ্রথম এ ১ম কলাম,
    তারপর ২য়, ৩য়, ...) আমারা correct Soln পাই,
    Soln = Query(BIT[k], max_value);

Let Input: 1 2 1 4 3
1st column :
------------
BIT[1][1st value(1)] = 1 [Base case]
BIT[2][1st value(1)] = 0
BIT[3][1st value(1)] = 0
BIT[4][1st value(1)] = 0
BIT[5][1st value(1)] = 0
2nd column :
------------
BIT[1][2nd value(2)] = 1 [Base case]
BIT[2][2nd value(2)] = 1
BIT[3][2nd value(2)] = 0
BIT[4][2nd value(2)] = 0
BIT[5][2nd value(2)] = 0
3rd column :
------------
BIT[1][3rd value(1)] = 1 [Base case]
BIT[2][3rd value(1)] = 0
BIT[3][3rd value(1)] = 0
BIT[4][3rd value(1)] = 0
BIT[5][3rd value(1)] = 0
4th column :
------------
BIT[1][4th value(4)] = 1 [Base case]
BIT[2][4th value(4)] = 3
BIT[3][4th value(4)] = 1
BIT[4][4th value(4)] = 0
BIT[5][4th value(4)] = 0
5th column :
------------
BIT[1][5th value(3)] = 1 [Base case]
BIT[2][5th value(3)] = 3
BIT[3][5th value(3)] = 1
BIT[4][5th value(3)] = 0
BIT[5][5th value(3)] = 0

For example, LIS of length 2 upto value 3(5th value)
= BIT[2][5th] + BIT[2][4th] + BIT[2][3rd]+BIT[2][2th]
= 3 + 3 + 0 + 1
=7
**/
