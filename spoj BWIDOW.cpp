#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin.sync();
        pair<int,int>p[n];
        int a,b,mx=0,mx2=0,index=0,index2=0;

        for(int i=0;i!=n; ++i)
        {
            cin>>a>>b;
            cin.sync();
            p[i]=make_pair(a,b);
        }

         for(int i=0;i!=n; ++i)
         {
             if(p[i].first > mx)
             {
                 mx=p[i].first;
                 index=i;
             }

         }

         for(int i=0;i!=n; ++i)
         {
             if(i==index)
             {
                 continue;
             }
             if(p[i].second > mx2)
             {
                 mx2=p[i].second;
                 index2=i;
             }
         }
         if(mx>mx2)
         {
             cout<<index+1<<endl;
         }
         else
         {
             cout<<-1<<endl;
         }
    }
    return 0;
}
/***
problem:
n সংখ্যক  ring আছে , with r and R(r=inner radious, R=outer)
ring x, ring y er ভেতর  দিয়ে  জেতে  পারে  যদি   R(x)<r(y).
n সংখ্যক  ring er মধ্যে  যদি  এমন একটা  ring থাকে  যেটার  মধ্যে  দিয়া  বাকি সব ring jete pare tobe ঐ রিং এর  index print koro, ohterwise print -1


**/
