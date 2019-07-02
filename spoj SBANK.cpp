#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>tmp;
        vector<int>v[n];
        for(int i=0;i<n;i++)
        {
            char ch;
            while(cin>>ch)
            {
                if(ch=='\n')
                {
                    break ;
                }
                tmp.push_back((int)ch);
            }
            v[i].push_back(tmp);
            tmp.clear();

        }
        sort(v[0],v[n-1]);

    }
}
