/**প্রব্লেমঃ একটা আয়তক্ষেত্র (lenget,width) দেওয়া আসে । ঐ তাকে  একটা বর্গক্ষেত্র বানাতে minimum কয়টা  আয়তক্ষেত্র  লাগে ?
Ans: big/small(if complete number) or big*small **/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,gcd,ans,max;
    long long int mult=0;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
        {
            break ;
        }
        if(a<b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        if(a%b==0)
        {
            ans=a/b;
        }
        else
        {
            ans=a*b;
        }

        cout<<ans<<endl;
    }
    return 0;
}

