#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int main()
{
    int n,mx,temp;
    while(scanf("%d",&n)!=EOF)
    {
        mx = 1;
        for(int i= 0; i<n; i++)
        {
            scanf("%d",&temp);
            if(a[temp-1] != 0) {
                a[temp] = a[temp-1]+1;
                mx = (a[temp]>mx)?a[temp]:mx;
            }
            else {

                a[temp] = 1;
            }
        }
        printf("%d",mx);
        memset(a,0,1000000);
    }
    return 0;
}
/**
Algorithm: use array[1000000];
if the sequence of current element exist in array then update current and mx
    else set a[current] to 1 i.e.a[temp]=1

a[temp-1] exist means temp is in  a "perfect increasing sequence";
**/

