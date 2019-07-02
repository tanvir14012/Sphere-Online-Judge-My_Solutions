#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int>m;
    map<string,int>::iterator it;

    int t,n;
    cin>>t;
    cin.sync();
    while(t--)
    {

    cin>>n;
    string str;
    while(n>=0)
    {
        getline(cin,str);
        m[str]++;
        n--;
    }
    it=m.begin();
    ++it;
    for(; it!=m.end(); ++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //system("pause");
    m.clear();
    }
    return 0;
}
