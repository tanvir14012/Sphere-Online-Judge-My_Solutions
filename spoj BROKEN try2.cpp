#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,m,x;
    vector<char>sub;
    string str;
    while(cin>>m)
    {
        getchar();
        int ct=0,ans=0,flag=0;
        if(m==0)
        {
            break ;
        }
        getline(cin,str);

        i=j=0;
        for(i=0; i!=str.size(); ++i)
        {
            x=1;
            sub.push_back(str[i]);
            ++ct;

            while(1)
            {
                if(str[i+x]=='\0')
                {
                    break;
                }
                //cout<<"i="<<i<<"  ,str[i+x]="<<str[i+x]<<"  ,ct="<<ct<<endl;
                flag=0;
                for(j=0; j!=sub.size(); ++j)
                {
                    if(str[i+x]==sub[j])
                    {
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    sub.push_back(str[i+x]);
                }
                if(sub.size() >m)
                {
                    break ;
                }
                ++ct;
                ++x;
                if(x>=str.size())
                {
                    break ;
                }
            }


            if(ct>ans)
            {
                ans=ct;
            }
            ct=0;
            x=0;
            sub.clear();
        }
        cout<<ans<<endl;
        str.clear();
        sub.clear();
    }
    //system("pause");
    return 0;
}

/**
3
aababbbqwer
0
**/
