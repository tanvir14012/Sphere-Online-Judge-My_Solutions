#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    stack<int>stk;
    int i,temp,ans=0;
    cin>>s;

    for(i=0; i!=s.length(); i++)
    {
        if(isalpha(s[i]))
        {
            switch(s[i])
            {
            case 'H':
                stk.push(1);
                break;
            case 'O':
                stk.push(16);
                break;
            case 'C':
                stk.push(12);
                break;

            }
        }
        else if(s[i]=='(')
        {
            stk.push(-1);
        }
        else if(s[i]==')')
        {
            temp=0;
            while(!stk.empty() && stk.top()!=-1)
            {
                temp+=stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(temp);
        }
        else if(isdigit(s[i]))
        {
            temp=stk.top();
            stk.pop();
            temp*=s[i]-48;
            stk.push(temp);
        }
    }
    while(!stk.empty())
    {
        ans+=stk.top();
        stk.pop();
    }
    cout<<ans<<endl;
    return 0;
}
