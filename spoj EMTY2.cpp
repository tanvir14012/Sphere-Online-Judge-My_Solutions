#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; ++a)
    {
        string s,s2,sub("100");
        vector<int>vct;
        cin>>s;
        while(1)
        {
            int v,i,j,badchar[256]= {0};
            for(int i=0; i!=3; i++)
            {
                v=3-i-1;
                badchar[sub[i]]=max(1,v);
            }

            for(i=0; i<=(s.length()-3);)
            {
                j=2;
                while(j>=0 && s[i+j]==sub[j])
                {
                    j--;
                }
                if(j<0)
                {

                    s.erase(s.begin()+i,s.begin()+i+3);
                    i=0;
                    j=2;
                    continue ;

                }
                if(3+i-1 <s.length())
                {
                    i+=badchar[s[i+3-1]];
                }
                else
                {
                    if(s.length()>=3)
                        i+=badchar[s[s.length()-1]];
                    else break;
                }
            }


            if(s.empty() || s.length() <3)
            {
                break;
            }
            s2.clear();
            vct.clear();

        }
        if(s.empty())
        {
            cout<<"Case "<<a<<": yes"<<endl;

        }
        else
        {
            cout<<"Case "<<a<<": no"<<endl;
            //cout<<s<<endl;
        }

    }
    //system("pause");
    return 0;
}

