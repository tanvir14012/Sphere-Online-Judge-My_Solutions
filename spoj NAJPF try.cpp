#include <bits/stdc++.h>
using namespace std;

void RK(string &str,string &sub,int q,vector<int>&v,int &ct);
#define base 256
int main()
{
    int t;
    string str,sub;
    vector<int>v;
    int ct;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        cin>>str>>sub;
        cin.ignore();

        ct=0;
        RK(str,sub,101,v,ct);


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

    }
    return 0;
}

void RK(string &str,string &sub,int q,vector<int>&v,int &ct)
{
    int i,j,p=0,t=0,h=1;
    int strl=str.length();
    int subl=sub.length();

    for(int i=0; i<subl-1; i++)
    {
        h=(h*base)%q;
    }
    for(i=0; i<subl; i++)
    {
        t=((base*t)+str[i])%q;
        p=((base*p)+sub[i])%q;
    }

    for(i=0; i<=(strl-subl); i++)
    {
        if(p==t)
        {
            for(j=0; j<subl; j++)
            {
                if(str[i+j]!=sub[j])
                {
                    break;
                }
            }
            if(j==subl)
            {
                v.push_back(i+1);
                ++ct;

            }
        }
        if(i<strl-subl)
        {
            t=(base*(t-str[i]*h)+str[i+subl])%q;
            if(t<0)
            {
                t+=q;
            }
        }
    }
}

