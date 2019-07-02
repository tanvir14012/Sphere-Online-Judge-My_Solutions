///786
#include <bits/stdc++.h>
using namespace std;

int  temp,t;
struct tree
{
    int  sum,mx,left,right;
};
inline int   Max(int   a,int   b)
{
    return (a>b)?a:b;
}

tree* creat(int   a[],int   n);
void creatUntil(int   a[],int   n,int   ss,int   se,tree* st,int   si);
int  find_range(int   n,tree* st,int   qs,int   qe);
tree find_rangeUntil(int   ss,int   se,int   qs,int   qe,tree* st,int   si);
void update(int a[],int n,tree* st,int index,int value);
void updateUntil(int a[],tree* st,int index,int value,int ss,int se,int si);

int  main()
{
    int   n,m,x,y,c,ans=0;
    scanf("%d",&n);
    int   a[n];
    for(int   i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    tree* st=creat(a,n);
    /**
    ///the tree in array
    for(int   i=0;i<2*(int  )pow(2,(int  )log2(n))-1;i++)
    {
        cout<<"____"<<(st+i)->mx<<endl;
    }
    **/
    scanf("%d",&m);
    for(int   i=0; i<m; i++)
    {

        scanf("%d%d%d",&c,&x,&y);
        if(c==1)
        {
        --x;
        --y;
        temp = find_range(n,st,x,y);
        printf("%d\n",temp);
        }
        else if(c==0)
        {
            --x;
            update(a,n,st,x,y);
        }

        temp=0;
    }
    delete [] st;
    return 0;
}

tree* creat(int   a[],int   n)
{

    int   x,mx;
    tree* st;
    x=(int   )ceil(log2(n));
    mx=2*(int  ) pow(2,x)-1;///I made mistake here. missed: 2 *.
    t = mx;
    st=new tree[mx];

    creatUntil(a,n,0,n-1,st,0);
    return st;
}
void creatUntil(int   a[],int   n,int   ss,int   se,tree* st,int   si)
{
    if(ss<0 || se>n-1)
    {
        return ;
    }
    if(ss==se)
    {
        st[si].sum=st[si].left=st[si].right=st[si].mx=a[ss];
        return;
    }
    int   mid=ss+(se-ss)/2;
    creatUntil(a,n,ss,mid,st,si*2+1);
    creatUntil(a,n,mid+1,se,st,si*2+2);

    st[si].sum=st[si*2+1].sum + st[si*2+2].sum;
    st[si].left=Max(st[si*2+1].left, st[si*2+1].sum + st[si*2+2].left);
    st[si].right=Max(st[si*2+2].right, st[si*2+2].sum+st[si*2+1].right);
    st[si].mx=Max(st[si*2+1].mx,Max(st[si*2+2].mx,st[si*2+1].right+st[si*2+2].left));
}

int  find_range(int   n,tree* st,int   qs,int   qe)
{
    if(qs<0 || qe>n-1 || qs>qe)
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }
    tree x=find_rangeUntil(0,n-1,qs,qe,st,0);
    return x.mx;
}

tree find_rangeUntil(int   ss,int   se,int   qs,int   qe,tree* st,int   si)
{
    int   mid=ss+(se-ss)/2;
    if(ss>qe || qs>se || qs>qe || si>=t)
    {
        tree tr;
        tr.left=tr.right=tr.mx=tr.sum=0;
        return tr;
    }
    else if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    else if(qe <= mid)
    {
        return find_rangeUntil(ss,mid,qs,qe,st,si*2+1);
    }
    else if( qs > mid)
    {
        return  find_rangeUntil(mid+1,se,qs,qe,st,si*2+2);
    }
    else
    {
        tree lp,rp,result;
        lp = find_rangeUntil(ss,mid,qs,qe,st,si*2+1);
        rp = find_rangeUntil(mid+1,se,qs,qe,st,si*2+2);

        result.sum = lp.sum + rp.sum;
        result.left = Max(lp.left, lp.sum + rp.left);
        result.right = Max(rp.right, rp.sum + lp.right);
        result.mx = Max(lp.mx, Max(rp.mx, lp.right + rp.left));
        return result;

    }
}

void update(int a[],int n,tree* st,int index,int value)
{
    if(index<0 || index>n-1)
    {
        return ;
    }
    a[index] = value;
    updateUntil(a,st,index,value,0,n-1,0);

}
void updateUntil(int a[],tree* st,int index,int value,int ss,int se,int si)
{
    if(index<ss || index>se)
    {
        return ;
    }
    if(ss==se && ss==index)
    {
        st[si].sum=st[si].left=st[si].right=st[si].mx=value;
        return ;
    }
    int   mid=ss+(se-ss)/2;
    if(index <=mid)
    {
        updateUntil(a,st,index,value,ss,mid,si*2+1);
    }
    else
    {
        updateUntil(a,st,index,value,mid+1,se,si*2+2);
    }

        st[si].sum=st[si*2+1].sum + st[si*2+2].sum;
        st[si].left=Max(st[si*2+1].left, st[si*2+1].sum + st[si*2+2].left);
        st[si].right=Max(st[si*2+2].right, st[si*2+2].sum+st[si*2+1].right);
        st[si].mx=Max(st[si*2+1].mx,Max(st[si*2+2].mx,st[si*2+1].right+st[si*2+2].left));
    }

