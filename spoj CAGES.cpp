#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    char str[4]="ABC";
    map<int,int>m;
    while(cin>>n)
    {
        long long int a[n],limit,x=0;
        char c[n+1];

        for(size_t i=1; i<=n; ++i)
        {
            cin>>a[i];
            //m[a[i]]=i;
        }
        set<long long int>s;

        for(size_t i=1; i<=n; ++i)
        {
            if(s.find(i)==s.end())
            {
                c[i]=str[x];
                s.insert(i);
                ++x;
                if(x==3)
                {
                    x=0;
                }
            }
            if(s.find(a[i])==s.end())
            {
                c[a[i]]=str[x];
                s.insert(a[i]);
                if(x==3)
                {
                    x=0;
                }
            }
        }

        //map<char,int>m1;
        for(size_t i=1; i!=n+1; ++i)
        {
           // m1[c[i]]++;
            cout<<c[i];
        }
        cout<<endl;
        s.clear();
        limit=x=0;
//        cout<<"A="<<m1['A']<<endl;
//        cout<<"B="<<m1['B']<<endl;
//        cout<<"C="<<m1['C']<<endl;
    }
    //system("pause");
    return 0;

}
