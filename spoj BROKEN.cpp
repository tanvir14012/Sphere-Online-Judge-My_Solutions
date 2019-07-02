#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    vector<char>sub;
    string str;
    while(cin>>m)
    {
        cin.sync();
        int ct=0,ans=0,flag;
        if(m==0)
        {
            break ;
        }
        getline(cin,str);
        cin.sync();

        for(int i=0; i<str.size(); ++i)
        {
            if(sub.empty())
            {
                ++ct;
                sub.push_back(str[i]);
            }
            else
            {
                if(sub.size() < m)
                {
                    flag=0;
                    for(vector<char>::iterator it=sub.begin(); it!=sub.end(); ++it)
                    {
                        if(str[i]==*it)
                        {
                            flag=1;
                            ++ct;
                        }
                    }
                    if(flag==0)
                    {
                        ++ct;
                        sub.push_back(str[i]);

                    }
                }
            }
            if(sub.size() >= m)
            {
                sub.clear();
                if(ct>ans)
                {
                    ans=ct;
                }
                ct=0;
            }
        }
        cout<<ans<<endl;
        str.clear();
        sub.clear();
    }
    return 0;
}
