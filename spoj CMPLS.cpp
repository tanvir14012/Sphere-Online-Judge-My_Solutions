/** 786 **/
#include <bits/stdc++.h>
using namespace std;
/*
void print(vector<int>& v)
{
    cout<<"-------"<<endl;
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<"-------"<<endl;
}
*/
int main()
{
    vector<vector<int> >v;
    vector<int>temp;
    bool flag;
    int t,n,c,check,x;
    cin>>t;
    while(t--)
    {
        flag = false;
        cin>>n>>c;
        for(int i = 0; i<n; i++)
        {
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
        check = (temp.size()>1)?temp[1]-temp[0]:temp[0];
        while(flag==false && temp.size()>1)
        {
            flag = true;
            check = temp[1]-temp[0];
            for(int i = 0; i<temp.size()-1; i++)
            {
                temp[i] = temp[i+1]-temp[i];
                if(temp[i]!=check)
                {
                    flag = false;//hole
                }
            }
            temp.pop_back();
            v.push_back(temp);
            //print(temp);
        }
        for(int i = 0; i<c; i++)
        {
            v[v.size()-1].push_back(check);
            for(int j = v.size()-2; j>=0; j--)
            {
                v[j].push_back(v[j].at(v[j].size()-1)+v[j+1].at(v[j+1].size()-1));
            }
        }
        for(int i = n; i<n+c; i++)
        {
            cout<<v[0].at(i)<<" ";
        }
        cout<<endl;
        v.clear();
        temp.clear();
    }
    return 0;
}
/**
1
8 3
1 2 4 7 11 16 22 29

**/
/**
Use difference method.
Algo: given array a of size n, on first step make an array a1 of size n-1 by the keeping the difference of two adjacent element of given array a. Like:a1[0] = a[1]-a[0] .....
a1[n-2] = a[n-1]-a[n-2]. Say array a1 as first row of difference table. Keep making rows until all elements in a row are same or there are only one element in a row.
so make a2, a3 .... until all elements become same or have only one element left. Now it's time to stop and expand those rows in a bottom-up manner. Let you made a table of size k = 3, a1(n-1 elements), a2(n-2 elements), a3(n-3 elements).
Now expand the last row of the difference table by "c" elements, with same elments or the remaining one.Here a3 will be expanded with "c" elements. Now you can expand the last element of a2[n-1](new expanded element) = a2[n-2]+a3[n-2](extended by constant difference), here array index starts from 0.
similarly, a1[n-1] = a1[n-2]+a2[n-3]
now original array, a[n] = a[n-1]+a1[n-2] is expanded.
If you repeat the bottom-up procedure "c" times, original array will be expanded by c number of elements. You can use "std vector" in c++
**/
