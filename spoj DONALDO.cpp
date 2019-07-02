#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,h,m,s,I,i,mx,ans;
    queue<long long int>q;
    scanf("%lld",&t);

    for(int it = 1; it<=t; it++)
    {
        scanf("%lld",&n);
        long long int a[n];
        for(i = 0; i<n; i++)
        {
            scanf("%lld%*c%lld%*c%lld",&h,&m,&s);
            a[i] = (h*3600 + m*60 + s);
        }
        scanf("%lld",&I);
        sort(a,a+n);

        ans = i = 0;

        while(i<n)
        {
            while(q.empty() || (i<n && a[i]-q.front()+1 <= I))
            {
                q.push(a[i]);
                i++;
            }
            ans = max(ans,(long long int)q.size());
            q.pop();
        }
        printf("Case %d: %lld\n",it,ans);
        while(!q.empty())
        {
            q.pop();
        }
    }
    return 0;
}
/*
কি এক  greedy অ্যালগরিদম রে বাবা , পুরাই  জ্বালাইয়া খাইল  ।
Concept : একটা সর্টেড অ্যাঁরে তে অর্ডার মেইনটেন করে first element (anyone taken as first:let fst) থেকে element গুলা একটা queue push করতে থাকলে যখন difference(element to be pushed,fst) > M হবে , তখন stop করলে  fst element থেকে stopped element-1  পর্যন্ত subset টির any two element এর maximum difference < M, যা (size of subset) fst element এর জন্য optimal solution. এভাবে fst+1, fst+2, .... n-1 এর জন্য optimal solution বের করে maximum subset size(queue size) ই solution.

Optimization :fst element এর জন্য stopped element index i হলে , fst+1,fst+2,...n-1 element এর জন্য i index বা তার আগে fst element এর তুলনায় ভাল solution possible না কারণ array is sorted. so, fst element pop করা হলে fst + 1 er জন্য stopped index for fst থেকে consider করতে হবে
*/
