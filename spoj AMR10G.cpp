#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,ans=0,min=INT_MAX;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<=(n-k);++i)
        {
            ans=a[i+k-1]-a[i];
            if(min>ans)
            {
                min=ans;
            }

        }
        cout<<min<<endl;
    }
    return 0;
}
/**
array টা sorted বিধায় (i and i+k-1) range er মধ্যেই a[i to i+k-1] element গুলার সাথে সম্প্রকিত সব combination এর  মধ্যে  যে  (group max-group min)minimum difference আছে ,
simulate kori: let k=4,a[1,2,3,4]={0,2,4,6,10,100}, 4 ta kore niya max o min er difference minimized হতে হবে।
logic: ascending order এ   k টা    নিয়ে     (group max-group min)minimum difference is always  <  উল্টাপাল্টা   order  k ta নিয়ে   (group max-group min)minimum difference if
if(min>ans)
            {
                min=ans;
            }
**/
