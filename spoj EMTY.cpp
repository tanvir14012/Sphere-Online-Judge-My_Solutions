#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,top=-1;

    char c,ch,ch2;
    cin>>t;
    for(int a=1; a<=t; ++a)
    {
        vector <char>v;
        string s;
        char stk[1000002];
        cin>>s;

        top=0;
        for(size_t i=0; i!=s.size();i++)
        {
            stk[top]=s[i];
            top++;
            if(top>=2)
            {
                if(stk[top]=='0' && stk[top-1]=='0' && stk[top-2]=='1')
                {
                    top-=2;
                }
            }
        }
        if(top==0)
        {
            cout<<"Case "<<a<<": yes"<<endl;
        }
        else
        {
            cout<<"Case "<<a<<": no"<<endl;
        }
    }
    return 0;
}
