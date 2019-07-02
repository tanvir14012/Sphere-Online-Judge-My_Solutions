#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.sync();
    while(t--)
    {
    string str,str2="";
    cin>>str;
    str2.insert(str2.begin(),str.rbegin(),str.rend());
    //cout<<str2<<endl;
    if(str==str2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}
