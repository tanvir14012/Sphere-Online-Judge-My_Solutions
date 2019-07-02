#include <bits/stdc++.h>
using namespace std;

void lps(int *a,char *sub,int n);
void kmp(string &str,char *sub,int n,int *a);

int main()
{
    string str;
    int n;
    while(cin>>n)
    {
        char sub[n];
        cin.ignore();
        cin.getline(sub,n+1);
        getline(cin,str);
        int *a = new int[n];
        lps(a,sub,n);
        kmp(str,sub,n,a);
        cout<<endl;
    }
    return 0;
}
void lps(int *a,char *sub,int n)
{
    int i,j;
    a[0] = 0;
    i = 1,j = 0;

    while(i != n)
    {
        if(sub[i] == sub[j])
        {
            j++;
            a[i] = j;
            i++;
        }
        else
        {
            if(j == 0)
            {
                a[i] = 0;
                i++;
            }
            else
            {
                j = a[j-1];
            }
        }
    }
}
void kmp(string &str,char *sub,int n,int *a)
{
    int i,j;
    i = j = 0;
    while(i != str.length())
    {
        if(str[i] == sub[j])
        {
            i++;
            j++;
        }
        if(j == n)
        {
            cout<<i-j<<endl;
            j = a[j-1];
        }
        if(i != str.length() && str[i] != sub[j])
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = a[j-1];
            }
        }
    }
}
