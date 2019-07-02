#include <bits/stdc++.h>
using namespace std;
#define mx 2700
int main()
{
    int n,t;
    cin>>t;
    vector<int>prime_factored(mx,0),ans;
    for(int i = 2; i<mx; i++)
    {
        if(prime_factored[i] == 0)
        {
            prime_factored[i] = 147;
        }
        else
        {
            continue ;
        }
        for(int j = i*2; j<mx; j+=i)
        {
            prime_factored[j]--;
            if(prime_factored[j]==-3)
            {
                ans.push_back(j);
            }
        }
    }
    sort(ans.begin(),ans.end());

    while(t--){
    cin>>n;
    cout<<ans[n-1]<<endl;
    }

    return 0;
}
/**
লজিক টা Sieve of Eratosthenes এর মত
প্রথমে vector<int>prime_factored(mx,0) এ সব গুলা  index=0 i.e. prime ধরে নেই, তারপর
২ থেকে mx পর্যন্ত  ২ এর সব  multiple এর index er value -1 করি ও prime_factored[২]=touched i.e.147
করে দেই।
তারপর ৩ যদি untouched(মানে  prime) হয়  তবে   ৩ থেকে mx পর্যন্ত  ৩ এর সব  multiple এর index er value -1 করি
prime_factored[৩]=touched i.e. 147 করি ।
এভাবে ..................।
কোন index এর value -3 মানে  ৩ তা prime দিয়া factored hoice, so add it to ans vector.
.....
ans vector টা unsorted , তাই সর্ট করে নিতে হবে।
soretd vector er n-1 তম element ই ans.
**/
