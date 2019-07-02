#include <bits/stdc++.h>
using namespace std;
int T[1002][1002];
int max(int i, int j)
{
    if (i < j) return j;
    else return i;
}

int main()
{
    char x[1002],y[1002];
    bool idx;
    while(gets(x))
    {
        gets(y);
        for(int i = 0; x[i]; i++)
        {
            //idx = (i+1) & 1;
            for(int j = 0; y[j]; j++)
            {
                if(x[i] == y[j])
                {
                    T[i+1][j+1] = T[i][j] + 1;
                }
                else
                {
                    T[i+1][j+1] = max(T[i][j+1], T[i+1][j]);
                }
            }
        }
        printf("%d\n",T[strlen(x)][strlen(y)]);
        memset(T,0,sizeof T);
    }
    return 0;
}
