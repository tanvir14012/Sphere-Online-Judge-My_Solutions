#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int>S;
    int n,temp,f,n1;
    cin>>n;
    n1=n;
    while(n1--)
    {
        cin>>temp;
        S.insert(temp);
        cin>>temp;
        while(temp--)
        {
            cin>>f;
            S.insert(f);
        }
    }
    cout<<S.size()-n<<endl;
    return 0;
}
