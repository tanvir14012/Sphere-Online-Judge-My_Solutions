#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s4;
long long tonumber()
{
    long long ten,b;
    b=0;
    ten=1;
    for(int i=s4.size()-1; i>=0; i--)
    {
        b=b+ten*(s4[i]-'0');
        ten=ten*10;
    }
    return b;
}
string mysubstring(string& s,int p, int q)
{
    string s1="A";
    s1.erase(0,s1.size());
    for(int i=p; i<=q; i++)
        s1=s1+s[i];
    return s1;
}
long long a[10000];
int main()
{
    long long k,t,i,j,n,m,b,c,d,p,q,ans;
    string s;
    cin>>t;
    for(k=1; k<=3*t; k++)
    {
        n=0;
        getline(cin,s);
        if(s.size()<1)
            continue;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                b=0;
                for(j=i; s[j]>='0' && s[j]<='9'; j++)
                    b++;
                n++;
                s4=mysubstring(s,i,j-1);
                a[n]=tonumber();
                i=j;
            }
        }
        ans=a[1];
        m=1;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                m++;
                if(s[i]=='+')
                    ans=ans+a[m];
                if(s[i]=='-')
                    ans=ans-a[m];
                if(s[i]=='*')
                    ans=ans*a[m];
                if(s[i]=='/')
                    ans=ans/a[m];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}




