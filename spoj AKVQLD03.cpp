#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int* creat(int a[],int n);
int creatUntil(int a[],int *st,int ss,int se,int si);
int getsum(int *st,int a[],int n,int qs,int qe);
int getsumUntil(int *st,int ss,int se,int qs,int qe,int si);
void update(int *st,int a[],int n,int i,int new_value);
void updateUntil(int *st,int ss,int se,int i,int dif,int si);

int main()
{
    long long int n,q,x,y;
    string cd,f="find",ad="add";
    while(cin>>n>>q)
    {
        const long long int ss=n;
        int *a;
        a=new int[ss];
        for(int it=0;it!=ss;++it)
        {
            a[it]=0;
        }

        int *st=creat(a,n);

        for(int i=0; i!=q; ++i)
        {
            cin>>cd;
            cin>>x>>y;
            if(cd==f)
            {
                printf("%d\n",getsum(st,a,n,x-1,y-1));
            }
            else if(cd==ad)
            {
                update(st,a,n,x-1,y);
            }
        }
    }

    return 0;
}

int* creat(int a[],int n)
{
    int x=(int)ceil(log2(n));
    int mx=2*(int)pow(2,x)-1;
    int*st=new int[mx];
    creatUntil(a,st,0,n-1,0);
    return st;
}

int creatUntil(int a[],int *st,int ss,int se,int si)
{
    if(ss==se)
    {
        st[si]=a[ss];/// I did a mistake in this line
        return a[ss];
    }
    int mid=ss+(se-ss)/2;
    st[si]=creatUntil(a,st,ss,mid,si*2+1)+creatUntil(a,st,mid+1,se,si*2+2);
    return st[si];
}

int getsum(int *st,int a[],int n,int qs,int qe)
{
    if(qs>qe || qe>n-1 || qs<0)
    {
        return 0;
    }
    return getsumUntil(st,0,n-1,qs,qe,0);
}

int getsumUntil(int *st,int ss,int se,int qs,int qe,int si)
{
    if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    if( ss>qe || qs>se)
    {
        return 0;
    }
    int mid=ss+(se-ss)/2;
    return (getsumUntil(st,ss,mid,qs,qe,si*2+1)+getsumUntil(st,mid+1,se,qs,qe,si*2+2));
}

void update(int *st,int a[],int n,int i,int new_value)
{
    if(i<0 || i>n-1)
    {
        return ;
    }
    int dif=new_value;
    a[i]=new_value;
    updateUntil(st,0,n-1,i,dif,0);
}
void updateUntil(int *st,int ss,int se,int i,int dif,int si)
{
    if(i<ss || i>se)
    {
        return ;
    }
    st[si]+=dif; ///I forget this line
    if(ss!=se)
    {
        int mid=ss+(se-ss)/2;
        updateUntil(st,ss,mid,i,dif,si*2+1);
        updateUntil(st,mid+1,se,i,dif,si*2+2);
    }

}
