#include <bits/stdc++.h>
using namespace std;
map<int,int>m;

int* creat(int a[],int n);
int creatUntil(int a[],int *st,int ss,int se,int si);
int getsum(int a[],int n,int qs,int qe,int *st);
int getsumUntil(int a[],int ss,int se,int qs,int qe,int *st,int si);
int main()
{
    int n,q,ans,t1,t2;
    scanf("%d%d",&n,&q);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int *st=creat(a,n);
    for(int i=0;i<q;i++)
    {
        m.clear();
        scanf("%d%d",&t1,&t2);
        ans=getsum(a,n,t1-1,t2-1,st);
        printf("%d\n",ans);
    }
    scanf("%d",&t1);
    return 0;
}
int* creat(int a[],int n)
{
    int x=(int)(ceil(log2(n)));
    int mx=2*(int)pow(2,x)-1; ///i mistake here
    int*st=new int[mx];


    creatUntil(a,st,0,n-1,0);
    return st;
}
int creatUntil(int a[],int *st,int ss,int se,int si)
{
    if(ss==se)
    {
        m[a[ss]]++;
        st[si]=m[a[ss]];
        return m[a[ss]];
    }
    int mid=(ss+se)/2;
    st[si]=max(creatUntil(a,st,ss,mid,si*2+1) , creatUntil(a,st,mid+1,se,si*2+2));
    return st[si];
}
int getsum(int a[],int n,int qs,int qe,int *st)
{
    if(qs>qe || qe>n-1 || qs<0)
    {
        return 0;
    }
    if(qs==qe)
    {
        return 1;
    }
    if(qs + 10 >= qe)
    {
        int mx=0;
        m.clear();
        for(int i=qs;i<=qe;i++)
        {
            m[a[i]]++;
            if(m[a[i]] > mx)
            {
                mx=m[a[i]];
            }
        }
        //cout<<"---------"<<mx<<endl;
        return mx;
    }
    return getsumUntil(a,0,n-1,qs,qe,st,0);
}
int getsumUntil(int a[],int ss,int se,int qs,int qe,int *st,int si)
{

    if(qs>qe || ss>qe || qs>se)
    {
        return 0;
    }
    if(ss==se)
    {
       st[si];

    }
    if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    int mid=(ss+se)/2;
    return max(getsumUntil(a,ss,mid,qs,qe,st,si*2+1) , getsumUntil(a,mid+1,se,qs,qe,st,si*2+2));
}
