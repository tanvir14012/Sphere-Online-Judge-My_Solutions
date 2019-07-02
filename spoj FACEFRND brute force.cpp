#include <bits/stdc++.h>
using namespace std;
int v[131];
int main()
{

    int n,temp,f,n1=0,ct=0,ct1;

    cin>>n;
    int a;
    vector<int>t;
    //memset(v,-1,10005);
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v[a%131]=147;

        cin>>temp;
        n1+=temp;
        while(temp--)
        {
            cin>>f;
            t.push_back(f);

        }
    }
    ct=0;
    for(int i=0; i!=t.size(); i++)
    {
        ct1=t[i]%131;
        if(v[ct1]==147)
        {
            ++ct;
        }
        v[ct1]=147;
    }
    cout<<t.size()-ct<<endl;
    return 0;
}

/** My first implementation of Hashing, it used division method  **/
