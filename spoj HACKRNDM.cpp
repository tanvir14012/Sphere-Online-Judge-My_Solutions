#include <bits/stdc++.h>
using namespace std;

bool BSearch(int a[],int left,int right,int key)
{
    int mid;
    while(left+1 < right)
    {
        mid = (left+right)/2;
        if(a[mid]==key)
        {
            return true;
        }
        else if(a[mid]>key)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return (a[left]!=key && a[right]!=key)?false:true;
}
int main()
{
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i = 0; i<n; i++)
    {
        if(BSearch(a,0,n-1,a[i]+k))
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/**
sort korar por a[i] er jonno BSearch() kore dhaka je a[i]+k ace kina.Thakle ans++
*/
