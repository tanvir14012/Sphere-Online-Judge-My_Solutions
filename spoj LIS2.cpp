#include <bits/stdc++.h>
using namespace std;
#define type vector<pair<int,int> >
#define type2 pair<int,int>
bool operator <(type2 a, type2 b)
{
    if(a.first<b.first && a.second<b.second)
    {
        return true;
    }
    return false;
}
bool operator ==(type2 a, type2 b)
{
    if(a.first == b.first || a.second == b.second)
    {
        return true;
    }
    return false;
}
bool operator >(type2 a, type2 b)
{
    if(a.first>b.first && a.second> b.second)
    {
        return true;
    }
    return false;
}
/*bool operator >=(type2 a,type2 b)
{
    if(a.first>b.first && a.second> b.second)
    {
        return true;
    }
    else if(a.first==b.first && a.second== b.second)
    {
        return true;
    }
    return false;
}*/
int ceilBinarySearch(type &temp,int right, type2 value)
{
    int left = 0,mid;
    while(left+1 < right)
    {
        mid = (left+right)/2;
        if(temp[mid] < value)
        {
            left = mid;
        }
        else
        {
            right= mid;
        }
    }
    return right;
}
void LIS(type &a)
{
    type temp(a.size(),make_pair(0,0));
    int length = 1;
    temp[0] = a[0];
    for(int i = 1; i<a.size(); i++)
    {
        if(a[i]<temp[0])
        {
            temp[0] = a[i];
        }
        else if(a[i] > temp[length-1])
        {
            temp[length] = a[i];
            length++;
        }
        else
        {
            int index = ceilBinarySearch(temp,length-1,a[i]);
            //cout<<"index = "<<index<<endl;
            if(temp[index] == a[i] )
            {
                //cout<<"cheer"<<endl;
                int minx , miny;
                minx = min(temp[index].first,a[i].first);
                miny = min(temp[index].second, a[i].second);
                temp[index] = make_pair(minx,miny);
            }
            else
            {
                temp[index] = a[i];
            }
        }
    }
    cout<<length<<endl;
}
int main()
{
    int n,x,y;
    vector<pair<int,int> >a;
    cin>>n;
    for(int i = 0; i!=n; i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    LIS(a);
    return 0;
}
/**
3
2 3
1 3
2 4
**/
/*
3
3 1
3 2
4 2
*/
