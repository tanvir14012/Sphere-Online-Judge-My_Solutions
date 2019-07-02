#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n,ans=0;
       scanf("%d",&n);
        /*
       for(int i=1;i<=11; ++i)
       {
           ans+=(int) (n/(int)pow(5,i));
           cout<<"::"<<n/(int)pow(5,i)<<endl;
       }
       cout<<ans<<endl;
       */

       while(n)
       {
           ans+=n/5;
           n/=5;
       }
       cout<<ans<<endl;

   }
   return 0;
}
