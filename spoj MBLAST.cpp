#include <bits/stdc++.h>
using namespace std;
int T[2003][2003],dash;
int topDown(string& x, string& y,int i, int j)
{
    int result=0;
    if(T[i][j] != -1)
    {
        return T[i][j];
    }
    if( i == x.length() || j == y.length())
    {
        if( i == x.length() && j == y.length())
        {
            result = 0;
        }
        else if(i == x.length())
        {
            result = (y.length()-j)*dash;
        }
        else if(j == y.length())
        {
            result = (x.length()-i)*dash;
        }
    }
    else
    {

        int temp1 =  dash + min(topDown(x,y,i+1,j), topDown(x,y,i,j+1)); ///temp1,temp2 globally declare kora error, karon LIFO order e value thake ja current call er part na o hote pare. Frastration + disappointment for this.
        int temp2 = abs(x[i]-y[j]) + topDown(x,y,i+1,j+1);
        result = min(temp2,temp1);
        // result = min(abs(x[i]-y[j]) + topDown(x,y,i+1,j+1), min(dash + topDown(x,y,i+1,j), dash + topDown(x,y,i,j+1)));
        // cout<<result<<endl;
    }
    T[i][j] = result;
    return result;
}
int main()
{
    string x,y;
    cin>>x>>y>>dash;
    memset(T,-1,sizeof T);
    cout<<topDown(x,y,0,0)<<endl;
    return 0;
}
/**

Description in notebook-2

Base case : 1. String X, Null = X.length() * dash
            2. String X, Y = Min (diff + both exclude the positioned char, dash + excluded 1 char from X, dash + excluded 1 char from Y).
In 2, u need to add dash cuz u need to fill the excluded char pos by a dash. For example :
a
b
2
=> a (Null)
   - b
   In null you are adding - by (1) so everything is okay


**/
