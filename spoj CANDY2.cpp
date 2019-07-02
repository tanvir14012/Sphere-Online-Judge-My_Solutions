#include <bits/stdc++.h>
using namespace std;

pair<int,int> find_max(int a[][3],int n,int k,int scpt);
long long int calculate(int array[][3],int n,int a,int b,int c);
bool distinct(int a,int b,int c);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][3];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    pair<int ,int>c[3],s[3],b[3];
    long long int ans=0,temp=0;
    int subscript[3]= {0};

    c[0]=find_max(a,n,INT_MAX,0);
    s[0]=find_max(a,n,INT_MAX,1);
    b[0]=find_max(a,n,INT_MAX,2);

    for(int i=1; i<3; i++)
    {
        c[i]=find_max(a,n,c[i-1].first,0);
        s[i]=find_max(a,n,s[i-1].first,1);
        b[i]=find_max(a,n,b[i-1].first,2);
    }
//    for(int i=0;i<3;i++)
//    {
//        cout<<" C::"<<c[i].first<<" , "<<c[i].second<<" )"<<endl;
//        cout<<" S::"<<s[i].first<<" , "<<s[i].second<<" )"<<endl;
//        cout<<" B::"<<b[i].first<<" , "<<b[i].second<<" )"<<endl;
//    }
    ans=INT_MAX;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                if(distinct(c[i].second,s[j].second,b[k].second)==true)
                {
                    temp=calculate(a,n,c[i].second,s[j].second,b[k].second);
                    if(ans>temp)
                    {
                        ans=temp;
                        subscript[0]=c[i].second;
                        subscript[1]=s[j].second;
                        subscript[2]=b[k].second;
                    }
                }
            }
        }
    }


    printf("Bag for chocolate candies: %d\nBag for strawberry candies: %d\nBag for banana candies: %d\n",subscript[0],subscript[1],subscript[2]);
    //system("pause");
    return 0;
}

pair<int,int> find_max(int a[][3],int n,int k,int scpt)
{
    pair<int ,int>p;
    int mx=-1,temp=-1,foul=0,foul2=0;
    for(int i=0; i<n; i++)
    {
        if(a[i][scpt]>mx  && a[i][scpt] < k)
        {
            mx=a[i][scpt];
            temp=i;
        }
        else if(a[i][scpt]>=mx )
        {
            foul=i;
            foul2=a[i][scpt];
        }
    }
    if(temp==-1)
    {
        mx=foul2;
        temp=foul;
    }
    p=make_pair(mx,temp);
    return p;
}

long long int calculate(int array[][3],int n,int a,int b,int c)
{
    long long int temp=0;
    for(int i=0; i<n; i++)
    {
        if(i!=a)
        {
            temp+=array[i][0];
        }
        if(i!=b)
        {
            temp+=array[i][1];
        }
        if(i!=c)
        {
            temp+=array[i][2];
        }
    }
    return temp;
}

bool distinct(int a,int b,int c)
{
    if(a!=b && a!=c && b!=c)
    {
        return true;
    }
    return false;
}
/**
logic+implementation পূরটাই আমার।
আমি যেটা করলাম সেটা হলঃ every column এর 1st,2nd and 3rd maximum value + subscript একটা array
of pair e রাখলাম। তারপর 3 ta nested loop চালিয়ে all possible ans er মধ্যে  minimum tar subscript
ber korlam.
**/
