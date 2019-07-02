#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,count;
    bool flag;
    char a[120000],ch;
    scanf("%d",&t);
    getchar();
    for(int i=1; i<=t; i++)
    {
        count = 0;
        while(1)
        {
            scanf("%c",&ch);
            flag = true;
            if(ch == '\n')
            {
                if(count==0)
                {
                    printf("Case %d: yes\n",i);
                }
                else
                {
                    printf("Case %d: no\n",i);
                }
                break;
            }

            a[count] = ch;
            if(count >=2)
            {
                while(count>=2 && a[count]=='0' && a[count-1]=='0' && a[count-2]=='1')
                {
                    count-=2;
                    flag = false;
                }
            }
            //cout<<"_____"<<a<<" ,"<<count<<endl;
            if(flag)count++;

        }
    }
    return 0;
}
