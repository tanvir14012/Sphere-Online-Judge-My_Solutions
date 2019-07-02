#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <climits>
using namespace std;


int *creat(int a[],int n);
int creat1(int a[],int ss,int se,int *st,int si);
int Count(int *tree,int *lazy,int n,int qs,int qe);
int Count1(int *tree,int *lazy,int ss,int se,int qs,int qe,int si);
int Minimum(int *st,int n,int qs,int qe);
int Minimum1(int *tree,int ss,int se,int qs,int qe,int si);
int MIN(int x,int y);
void update(int a[],int *st,int *lazy,int n,int qs,int qe,int new_value);
void updateUntil(int *st,int *lazy,int ss,int se,int qs,int qe,int dif,int si);
void Eat(int a[],int *st,int n,int dif,int pos);
void EatUntil(int *st,int ss,int se,int dif,int pos,int si);


int main()
{
    int n,q;
    string s1;
    int x,y;
    scanf("%d%d",&n,&q);
    const int sz=n;
    int a[sz];
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
    }
    int *st=creat(a,n);
    int xx=(int)(ceil(log2(n)));
    int mx=2*(int)pow(2,xx)-1;
    int*lazy=new int[mx];
    ///cout<<"mx="<<mx<<endl;
    for(size_t i=0;i<mx;++i)
    {
        lazy[i]=0;
    }
    while(q--)
    {
        cin>>s1>>x>>y;

        if(s1=="COUNT")
        {
            cout<<Count(st,lazy,n,x-1,y-1)-Minimum(st,n,x-1,y-1)<<endl;
        }
        else if(s1=="GROW")
        {
            update(a,st,lazy,n,x,y-1,y-1);
        }
        else if(s1=="EAT")
        {
            Eat(a,st,n,x,y-1);
        }
    }
    return 0;
}

int *creat(int a[],int n)
{
    int x=(int) ceil(log2(n));
    int mx=2*(int)pow(2,x)-1;
    int *tree=new int[mx];
    creat1(a,0,n-1,tree,0);
    return tree;
}

int creat1(int a[],int ss,int se,int *st,int si)
{
    if(ss==se)
    {
        st[si]=a[ss];
        return a[ss];
    }
    int mid=ss+(se-ss)/2;
   st[si]= creat1(a,ss,mid,st,si*2+1)+creat1(a,mid+1,se,st,si*2+2);
   return st[si];
}

int Count(int *tree,int *lazy,int n,int qs,int qe)
{
    if(qs>qe || qs<0 || qe>(n-1))
    {
        return 0;
    }
    return Count1(tree,lazy,0,n-1,qs,qe,0);
}

int Count1(int *st,int *lazy,int ss,int se,int qs,int qe,int si)
{
    if(lazy[si]!=0)
    {
        st[si]=(se-ss+1)*lazy[si];
        if(ss!=se)
        {
            lazy[si*2+1]+=lazy[si];
            lazy[si*2+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if(qs<=ss  && qe>=se)
    {
        return st[si];
    }
    if(qs>se || qe<ss)
    {
        return 0;
    }
    int mid=ss+(se-ss)/2;
    return (Count1(st,lazy,ss,mid,qs,qe,si*2+1)+Count1(st,lazy,mid+1,se,qs,qe,si*2+2));
}

int Minimum(int *st,int n,int qs,int qe)
{
    if(qs>qe || qs<0 || qe>(n-1))
    {
        return 0;
    }
    return Minimum1(st,0,n-1,qs,qe,0);
}

int Minimum1(int *tree,int ss,int se,int qs,int qe,int si)
{
    if(qs<=ss && qe>=se)
    {
        return tree[si];
    }
    if(qs>se || qe<ss)
    {
        return INT_MAX;
    }
    int mid=ss+(se-ss)/2;
    return MIN(Minimum1(tree,ss,mid,qs,qe,si*2+1),Minimum1(tree,mid+1,se,qs,qe,si*2+2));
}

int MIN(int x,int y)
{
    return (x<y)?x:y;
}

void update(int a[],int *st,int *lazy,int n,int qs,int qe,int new_value)
{
    if(qs>qe || qs<0 || qe>(n-1))
    {
        return ;
    }
    int dif=new_value;
    updateUntil(st,lazy,0,n-1,qs,qe,dif,0);
}

void updateUntil(int *st,int *lazy,int ss,int se,int qs,int qe,int dif,int si)
{
     if(lazy[si]!=0)
    {
        st[si]=(se-ss+1)*lazy[si];
        if(ss!=se)
        {
            lazy[si*2+1]+=lazy[si];
            lazy[si*2+2]+=lazy[si];
        }
        lazy[si]=0;
    }
     if(ss>se || qs>se || qe<ss)
    {
        return ;
    }

     if(qs<=ss && qe>=se)
     {
         st[si]+=(se-ss+1)*dif;

         if(ss!=se)
         {
             lazy[si*2+1]+=dif;
             lazy[si*2+1]+=dif;
         }
         return ;
     }
     int mid=ss+(se-ss)/2;
     updateUntil(st,lazy,ss,mid,qs,qe,dif,si*2+1);
     updateUntil(st,lazy,mid+1,se,qs,qe,dif,si*2+2);
      st[si]=st[si*2+1]+st[si*2+2];


}

void Eat(int a[],int *st,int n,int dif,int pos)
{
    if(pos<0 || pos>n-1)
    {
        return ;
    }
    a[pos]-=dif;
    EatUntil(st,0,n-1,dif,pos,0);
}

void EatUntil(int *st,int ss,int se,int dif,int pos,int si)
{
    if(pos<ss || pos>se)
    {
        return ;
    }
    st[si]-=dif;
    if(ss!=se)
    {
        int mid=ss+(se-ss)/2;
        EatUntil(st,ss,mid,dif,pos,si*2+1);
        EatUntil(st,mid+1,se,dif,pos,si*2+2);
    }

}
/**
12
1 6 4 8 9 5 21 3 6 10 11 5
9
COUNT 1 7
EAT 2 4
GROW 4 8
COUNT 5 7
COUNT 3 9
COUNT 4 4
COUNT 10 11
EAT 5 10
COUNT 0 11
**/
