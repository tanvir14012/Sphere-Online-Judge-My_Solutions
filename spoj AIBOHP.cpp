#include <bits/stdc++.h>
using namespace std;
int T[6101][6101];
int topDown(string &str, int i, int j)
{
    int result = 0;
    if(T[i][j] != -1) {
        return T[i][j];
    }
    if(i == j)
    {
        result = 0;
    }
    else if(abs(i-j) == 1)
    {
        result = (str[i] == str[j]) ? 0 : 1;
    }
    else
    {
        if(str[i] == str[j])
        {
            result = topDown(str, i+1, j-1);
        }
        else
        {
            result = 1 + min(topDown(str,i+1,j), topDown(str,i,j-1));
        }
    }
    T[i][j]= result;
    return result;
}

int main()
{
    int n;
    string s;
    scanf("%d",&n);
    while(n--)
    {
        cin>>s;
        memset(T,-1,sizeof T);
        printf("%d\n", topDown(s,0,s.length()-1));
    }
    return 0;
}
