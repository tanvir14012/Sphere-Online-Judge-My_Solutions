#include <bits/stdc++.h>
using namespace std;
void C(long long int  n, long long int  k);
int main()
{
    int t;
    long long int  n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        C(n-1,k-1);///k-1 because one is already taken for satisfying condition.
    }
    return 0;
}
void C(long long int  n, long long int  k)
{
    long long int  temp = 1;
    if(k > n-k)
    {
        k = n-k;
    }
    for(size_t i = 0; i<k ; i++)
    {
        temp *= (n-i);
        temp /= (i+1);
    }
    cout<<temp<<endl;
}
