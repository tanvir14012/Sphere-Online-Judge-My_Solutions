#include <bits/stdc++.h>
using namespace std;

void lps(int *a,string &sub,int sz);
int main()
{
    int t;
    string str,sub;
    vector<int>v;
    int i,j,ct;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        cin>>str>>sub;
        cin.ignore();
        int *a=new int[sub.size()];
        lps(a,sub,sub.size());
        i=j=ct=0;
        while(i!=str.size())
        {
            if(str[i]==sub[j])
            {
                i++;
                j++;
            }
            if(j==sub.length())
            {
                v.push_back(i-j+1);
                ++ct;
                j=a[j-1];
            }
            else if(i!=str.length() && str[i]!=sub[j])
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=a[j-1];
                }
            }
        }
        if(ct)
        {
            cout<<ct<<endl;
            for(auto it=v.begin(); it!=v.end(); ++it)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Not Found"<<endl;
        }
        v.clear();
        delete []a;
    }
    return 0;
}
void lps(int *a,string &sub,int sz)
{
    int i,j;
    i=1,j=0;
    a[0]=0;
    while(i!=sz)
    {
        if(sub[i]==sub[j])
        {
            j++;
            a[i]=j;
            i++;
        }
        else
        {
            if(j==0)
            {
                a[i]=0;
                i++;
            }
            else
            {
                j=a[j-1];
            }
        }
    }

}
