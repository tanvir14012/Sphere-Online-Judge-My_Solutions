#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,ct=0,ans=0,a,b;
    map<long long int,char>m;
    map<long long int,char>::iterator it;
    cin>>t;
    cin.sync();
    while(t--)
    {
        cin>>n;
        for(int i=0; i!=n; ++i)
        {
            cin>>a>>b;
            cin.sync();
            m[a]='l';
            m[b]='r';

        }
        ct=ans=0;
        for(it=m.begin(); it!=m.end(); ++it)
        {
            if(it->second=='l')
            {
                ++ct;
            }
            else if(it->second=='r')
            {
                --ct;
            }
            if(ct>ans)
            {
                ans=ct;

            }
        }


        cout<<ans<<endl;
        m.clear();
    }

    return 0;
}
/**
1
5
1 7
2 4
6 9
3 8
5 10
**/

