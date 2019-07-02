#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int,int>& a, pair<int,int>& b)
    {
        return (a.second<b.second);
    }
};
int main()
{
    int t,n,ans,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pair<int,int>a[n];
        for(int i = 0; i<n; i++)
        {
            cin>>a[i].first>>a[i].second;
        }
        sort(a,a+n,compare());
        ans = 1;
        temp = 0;
        for(int i =1; i<n; i++)
        {
            if(a[i].first >= a[temp].second)
            {
                ans++;
                temp = i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**
Algorithm: Activity Selection Problem(greedy)
Source :geeksforgeeks.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
…….a) If the start time of this activity is greater than or equal to the
finish time of previously selected activity then select this activity and print it.
*/
