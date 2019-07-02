#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n,i,j,k;
    cin>>n;
    while(n!=0)
    {
        //getchar();
        cin.ignore();
        string s;
        getline(cin,s);
        map<char, int>m;
        set<char>Set;
        i=j=k=0;

        for(i=0;i<s.length() && i<n;i++)
        {
            if(m[s[i]]==0)
            {
                m[s[i]]=1;
                Set.insert(s[i]);
            }
            else
            {
                m[s[i]]++;
            }
        }
        j=0;
        k=i-j;

        while(i < s.length())
        {
            {
                Set.insert(s[i]);
            }
            m[s[i]]++;
            //if(m[s[i]]==1)

            if(Set.size() > n)
            {
                while(m[s[j]]>1)
                {
                    m[s[j++]]--;
                }
                m[s[j]]=0;
                Set.erase(s[j++]);
            }

            i++;
            k=max(k,i-j);
        }
        cout<<k<<endl;
        m.clear();
        Set.clear();
        cin>>n;
    }
    return 0;
}
