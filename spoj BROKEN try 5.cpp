#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i,j,k;
    while(cin>>n)
    {
        if(n==0)
        {
            break ;
        }
        string s;
        getchar();
        getline(cin,s);
        map<char,long long int>m;
        set<char>Set;
        i=j=k=0;

        while(i<s.size() && i<n)
        {
            m[s[i]]++;
            if(m[s[i]]==1)
            {
                Set.insert(s[i]);
            }
            i++;
        }
        k=i-j;

        while(i < s.size())
        {
            m[s[i]]++;
            if(m[s[i]]==1)
            {
                Set.insert(s[i]);
            }
            if(Set.size() > n)
            {
                while(m[s[j]]>1)
                {
                    m[s[j]]--;
                    j++;
                }
                m[s[j]]=0;
                Set.erase(s[j]);
                j++;
            }

            i++;
            k=max(k,i-j);
        }
        cout<<k<<endl;
        m.clear();
        Set.clear();
    }
    return 0;
}

