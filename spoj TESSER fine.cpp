#include <bits/stdc++.h>
using namespace std;

void lps(char *str,int sz,int *a);
bool inline checker(int a,char c,int b);

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long int a[n];
        for(int i=0; i!=n; ++i)
        {
            scanf("%lld",&a[i]);
        }
        char str[n];
        scanf("%s",str);
        int sz=strlen(str);
        int *temp=new int[sz];
        lps(str,sz,temp);
        int i=1,j=0,flag=147;
        bool b;
        while(i!=n)
        {
            b=checker(a[i],str[j],a[i-1]);
            if(b)
            {
                i++;
                j++;
            }
            if(j==sz)
            {
                printf("YES\n");
                flag=0;
                break;
            }
            else if(i!=n && b==false)
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=temp[j-1];
                }
            }
        }
        if(flag==147)
        {
            printf("NO\n");
        }
        delete [] temp;
    }
    return 0;
}

void lps(char *str,int sz,int *a)
{
    int i=1,j=0;
    a[0]=0;
    while(i!=sz)
    {
        if(str[i]==str[j])
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
bool inline checker(int a,char c,int b)
{
    if(c=='G')
    {
        return a>b;
    }
    else if(c=='L')
    {
        return a<b;
    }
    else if(c=='E')
    {
        return a==b;
    }
}

