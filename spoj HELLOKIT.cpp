#include <bits/stdc++.h>
using namespace std;

char temp[10007],str[10007];
int main()
{
    int n;
    while(scanf("%s",temp)==1){

    if(temp[0]=='.')
    {
        break;
    }
    scanf("%d",&n);
    for(int i=0; i<=n; i++)
    {
        strcat(str,temp);
    }
    int i,j,len;
    i=0;
    j=strlen(str)-strlen(temp)-1;
    len=strlen(temp)-1;

    while(i<=len)
    {
        for(int it=i; it<=j; it++)
        {
            printf("%c",str[it]);
        }
        i++;
        j++;
        printf("\n");
    }
    memset(temp,0,strlen(temp));
    memset(str,0,strlen(str));

}
    return 0;
}
