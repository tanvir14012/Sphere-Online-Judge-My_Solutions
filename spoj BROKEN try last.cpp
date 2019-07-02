#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n,i,j,k;
    string s;
    cin>>n;
    while(n!=0)
    {
        getchar();
        getline(cin,s);
        map<char,int> m;
        set<char> mySet;
        for(i=0; i<s.length() && i<n; i++)
        {
            if(!m[s[i]])
            {
                m[s[i]]=1;
                mySet.insert(s[i]);
            }
            else
            {
                m[s[i]]++;
            }
        }
        j=0;
        k = i-j;
        //cout<<"Before , k= "<<k<<endl;
        while( i < s.length() )
        {
            //cout<<"insert ="<<s[i]<<endl<<"i="<<i<<"  , j="<<j<<endl;
            mySet.insert(s[i]);
            m[s[i]]++;
            if( mySet.size() > n)
            {
                //cout<<"last insert ="<<s[i]<<endl<<"i="<<i<<"  , j="<<j<<endl;
                while( m[s[j]]>1)
                {
                    m[s[j++]]--;
                    //cout<<"Help: m[s[j]]:="<<m[s[j]]<<" , "<<"s[j]="<<s[j]<<" ,j="<<j<<endl;
                }
                m[s[j]]=0;
                //cout<<"erase: s[j]:="<<s[j]<<endl;
                mySet.erase(s[j++]);
            }
            i++;
            //cout<<"Max ,i="<<i<<" , j="<<j<<" , (i-j)="<<i-j<<" k="<<k<<endl;
            k = max(k,i-j);
        }
        cout<<k<<endl;
        cin>>n;
    }
}
/*
3
aabaaabbqw
*/
