#include <bits/stdc++.h>
using namespace std;

void multiply(string s1,string s2,string &ans);

int main()
{
    int t;
    string s1,s2,ans;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        multiply(s1,s2,ans);
        cout<<ans<<endl;
    }
    return 0;
}

void multiply(string s1,string s2,string &answer)
{
    int i,j,r=-1,length,carry,ans,sz;
    sz=(s1.size()+s2.size());
    char temp[sz];
    memset(temp,48,sz);

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    for(i=0;i<s1.length();i++)
    {
        carry=0;
        for(j=0;j<s2.length();j++)
        {
            ans=((s1[i]-'0')*(s2[j]-'0')) + carry + (temp[i+j]-'0');
            carry=ans/10;
            temp[i+j]=ans%10 + '0';
            if(i+j > r)
            {
            r=i+j;
            }
        }
        while(carry !=0)
        {
            ans=temp[i+j]-'0' + carry;
            carry=ans/10;
            temp[i+j]=ans%10 + '0';
            if(i+j > r)
            {
            r=i+j;
            }
        }
    }

    while(r>0 && temp[r]=='0')
    {
    --r;
    }
    temp[r+1]='\0';
    answer.assign(temp);
    reverse(answer.begin(),answer.end());
}
