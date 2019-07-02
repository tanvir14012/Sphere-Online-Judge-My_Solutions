#include <bits/stdc++.h>
using namespace std;
#define IDX 2001
int lcs[IDX][IDX];

int main()
{
    int t;
    char str1[IDX], str2[IDX];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",str1,str2);
        memset(lcs,0,sizeof lcs);
        for(int i = 0; i<strlen(str1); i++)
        {
            for(int j =0 ; j<strlen(str2); j++)
            {
                if(i == 0 )
                {
                    if(j != 0)
                    {
                        lcs[i][j] = (str1[i] == str2[j]) ? lcs[i][j-1] : lcs[i][j-1]+1;
                    }
                    else
                    {
                        lcs[i][j] = (str1[i] == str2[j]) ? 0 : 1;
                    }
                }
                else if(j == 0)
                {
                    if(i != 0)
                    {
                        lcs[i][j] = (str1[i] == str2[j]) ? lcs[i-1][j] : lcs[i-1][j]+1;
                    }
                    else
                    {
                        lcs[i][j] = (str1[i] == str2[j]) ? 0 : 1;
                    }
                }

                else if(i == j)
                {
                    if(str1[i] == str2[j])
                    {
                        lcs[i][j] = lcs[i-1][j-1];
                    }
                    else
                    {
                        lcs[i][j] = min(i, lcs[i-1][j-1] + 1);
                    }
                }
                else
                {
                    if(str1[i] == str2[j])
                    {
                        lcs[i][j] = min(lcs[i][j-1], lcs[i-1][j-1]);
                    }
                    else
                    {
                        lcs[i][j] = min(lcs[i][j-1], min(lcs[i-1][j], lcs[i-1][j-1])) + 1;
                    }

                }
            }
        }
        printf("%d\n", lcs[strlen(str1)-1][strlen(str2)-1]);
        /*for(int i = 0; i<strlen(str1); i++)
        {
            for(int j =0 ; j<strlen(str2); j++)
            {
                printf("%d  ",lcs[i][j]);
            }
            cout<<endl;
        }*/
    }
    return 0;
}
/*
2
QWERT
ERTQW
BOOK
MOVIES


*/
