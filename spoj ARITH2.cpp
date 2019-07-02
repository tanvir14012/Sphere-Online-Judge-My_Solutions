#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int digit(char c)
{
    return (c>='0' && c<='9');
}
int operatoor(char c)
{
    return (c=='+' || c=='-' ||c=='*' ||c=='/' || c == '=');
}

int main()
{
    char ch,op;
    char input[100007],t[100007];
    long long int n, ans=0, temp=0;
    int h,j,i=0;

    scanf( "%lld", &n );
    getchar();

    while ( n )
    {
        while((ch=getchar())!='=')
        {
            input[i++]=ch;
        }
        input[i]='=';
        ++i;
        input[i]='\0';
        //gets(input);
        puts(input);
        if(strcmp(input,"\n")==0)
        {
            continue;
        }
        for(i=0,j=0; digit((ch=input[i])); i++)
        {
            t[j++]=ch;
        }
        t[j]='\0';
        h=1;
        j--;
        while(j!=-1)
        {
            ans+=(t[j]-48)*(h);
            //printf("%lld\n",ans);
            j--;
            h*=10;

        }

        //printf("%lld",ans);

        while(1)
        {
            for(; !operatoor((ch=input[i])); i++)
            {

            }
            op=input[i];
            // printf("ttttt:%c\n",op);
            if(op == '=')
            {
                break ;
            }

            while(!digit(input[i]))
            {
                i++;
            }

            for(j=0; digit((ch=input[i])); i++)
            {
                t[j++]=ch;

            }
            t[j]='\0';
            //puts(t);
            h=1;
            j--;
            temp=0;
            while(j!=-1)
            {
                temp+=(t[j]-48)*(h);
                //printf("%lld\n",temp);
                j--;
                h*=10;

            }
            //printf("%c::%lld\n",op,temp);
            //printf("ans::%lld\n op::%c \n temp::%lld\n",ans,op,temp);
            switch(op)
            {

            case '+':
                ans+=temp;
                break;
            case '-':
                ans-=temp;
                break;
            case '*':
                ans*=temp;
                break;
            case '/':
                ans/=temp;
                break;

            }

        }
        printf("%lld\n",ans);
        n--;
        ans=temp=0;
        strcpy(t,"\0");
    }
    //system("pause");
    return 0;
}

/**
1

6 / 84 - 64 - 84 - 8 - 4 / 8 - 4 / 96848 + 4 / 8494 + 9 * 4 / 84 =
*/
