#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool flag;
    int n,i,j;
    char str[200];
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
        {
            break ;
        }
        getchar();
        cin.getline(str,200);
        int sz = strlen(str)/n;
        char a[sz][n];
        i = j = 0;
        flag = true;
        for(int it = 0; str[it] !='\0' ; it++)
        {
            if(i != n && i!= -1)
            {
                //cout<<j<<" "<<i<<endl;
                a[j][i] = str[it];
                //cout<<a[j][i]<<" ";
                if(flag)
                {
                    i ++;
                }
                else
                {
                    i --;
                }
            }
            else if(i == n)
            {
                flag = false;
                i --;
                j ++;
                it --;
                //cout<<endl;
            }
            else if(i == -1)
            {
                flag = true;
                i++;
                j++;
                it--;
                //cout<<endl;
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<sz; j++)
            {
                printf("%c",a[j][i]);
            }
        }
        cout<<endl;
    }
    return 0;
}
