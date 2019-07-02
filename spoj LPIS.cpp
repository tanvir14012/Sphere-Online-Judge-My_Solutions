#include <bits/stdc++.h>
using namespace std;
/** More efficient way is use an array[1000000]. See spoj LPIS try1 **/
int main()
{
    int n,mx,temp;
    //map<int,int>m;
    unordered_map<int,int>m;
    while(cin>>n)
    {
        m.clear();
        mx = 1;
        for(int i= 0; i<n; i++)
        {
            scanf("%d",&temp);
            if(m.find(temp-1) != m.end()) {
                m[temp] = m[temp-1]+1;
                mx = (m[temp]>mx)?m[temp]:mx;
            }
            else {

                m[temp] = 1;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
/**
Algorithm: using unordered_map<int,int>m; array is better though.
if the sequence of current element exist in map then update current and mx
    else set m[current] to 1 i.e.m[temp]=1

m[temp-1] exist means temp is in perfect sequence;
**/
