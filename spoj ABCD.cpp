#include <bits/stdc++.h>
using namespace std;

set<char>S;
void re_add()
{
    S.clear();
    for(char i='A'; i<='D'; i++)
    {
        S.insert(i);
    }
}
void erase_(int i,char a,char b)
{
    S.erase(S.find(a));
    S.erase(S.find(b));
}
int main()
{
    int n;
    cin>>n;
    getchar();
    n*=2;
    char a[2][n];
    set<char>::iterator it;


    for(int i=0; i<n; i++)
    {
        cin>>a[0][i];
    }
//    for(int i=0; i<n; i++)
//    {
//        cout<<a[0][i];
//    }
    getchar();
    for(int i=0; i<=(n-2); i+=2)
    {
        re_add();
        erase_(i,a[0][i],a[0][i+1]);
        it=S.begin();

        if(i!=0 && (*it)==a[1][i-1])
        {
            ++it;
            a[1][i]=*it;
            --it;
            a[1][i+1]=*it;
        }
        else
        {
            a[1][i]=*(it);
            ++it;
            a[1][i+1]=*it;
        }

    }
    for(int i=0; i<n; i++)
    {
        cout<<a[1][i];
    }
    cout<<endl;

    return 0;
}
/**
concept:
Work with blocks of 2x2 colors in order to have the four distinct colors in each cell (so we will have the same number of cells for each color).

Assign the remaining colors to the empty cells, checking that no two adjacent cells have the same color.
**/
