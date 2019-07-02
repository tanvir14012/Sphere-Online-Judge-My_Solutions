///786
///spoj GSS1 tight is well furnished than this
#include <bits/stdc++.h>
using namespace std;

long long int temp,t;
struct tree
{
    long long int sum,mx,left,right;
};
inline long long int  Max(long long int  a,long long int  b)
{
    return (a>b)?a:b;
}
inline long long int  Max2(long long int  a,long long int  b,long long int c)
{
    return Max(a, Max(b, c));
}
tree* creat(long long int  a[],long long int  n);
void creatUntil(long long int  a[],long long int  n,long long int  ss,long long int  se,tree* st,long long int  si);
long long int find_range(long long int  n,tree* st,long long int  qs,long long int  qe);
tree find_rangeUntil(long long int  ss,long long int  se,long long int  qs,long long int  qe,tree* st,long long int  si);

int  main()
{
    long long int  n,m,x,y,ans=0;
    scanf("%lld",&n);
    long long int  a[n];
    for(long long int  i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
    tree* st=creat(a,n);
    /**
    ///the tree in array
    for(long long int  i=0;i<2*(long long int )pow(2,(long long int )log2(n))-1;i++)
    {
        cout<<"____"<<(st+i)->mx<<endl;
    }
    **/
    scanf("%lld",&m);
    for(long long int  i=0; i<m; i++)
    {

        scanf("%lld%lld",&x,&y);
        --x;
        --y;
        temp = find_range(n,st,x,y);
        printf("%lld\n",temp);

        temp=0;
    }
    delete [] st;
    return 0;
}

tree* creat(long long int  a[],long long int  n)
{

    long long int  x,mx;
    tree* st;
    x=(long long int  )ceil(log2(n));
    mx=2*(long long int ) pow(2,x)-1;///I made mistake here. missed: 2 *.
    t = mx;
    st=new tree[mx];

    creatUntil(a,n,0,n-1,st,0);
    return st;
}
void creatUntil(long long int  a[],long long int  n,long long int  ss,long long int  se,tree* st,long long int  si)
{
    if(ss<0 || se>n-1)
    {
        return ;
    }
    if(ss==se)
    {
        (st+si)->sum=(st+si)->left=(st+si)->right=(st+si)->mx=a[ss];
        return;
    }
    long long int  mid=ss+(se-ss)/2;
    creatUntil(a,n,ss,mid,st,si*2+1);
    creatUntil(a,n,mid+1,se,st,si*2+2);

    (st+si)->sum=(st+(si*2+1))->sum + (st+(si*2+2))->sum;
    (st+si)->left=Max((st+(si*2+1))->left, (st+(si*2+1))->sum + (st+(si*2+2))->left);
    (st+si)->right=Max((st+(si*2+2))->right, (st+(si*2+2))->sum+(st+(si*2+1))->right);
    //(st+si)->mx=Max((st+(si*2+1))->mx,Max((st+(si*2+2))->mx,(st+(si*2+1))->right+(st+(si*2+2))->left));
    (st+si)->mx=Max2((st+(si*2+1))->mx,(st+(si*2+2))->mx,(st+(si*2+1))->right+(st+(si*2+2))->left);
}

long long int find_range(long long int  n,tree* st,long long int  qs,long long int  qe)
{
    if(qs<0 || qe>n-1 || qs>qe)
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }
    tree x=find_rangeUntil(0,n-1,qs,qe,st,0);
    return x.mx;
}

tree find_rangeUntil(long long int  ss,long long int  se,long long int  qs,long long int  qe,tree* st,long long int  si)
{
    long long int  mid=ss+(se-ss)/2;
    if(ss>qe || qs>se || qs>qe || si>=t)
    {
        //cout<<"Case 1"<<endl;
        tree tr;
        tr.left=tr.right=tr.mx=tr.sum=0;
        return tr;
    }
    else if(qs<=ss && qe>=se)
    {
        //cout<<"Case 2"<<endl;
        //temp = (st+si)->mx;
        return *(st+si);
    }
    else if(qe <= mid)
    {
        //cout<<"Case 3"<<endl;
        return find_rangeUntil(ss,mid,qs,qe,st,si*2+1);//find_rangeUntil(ss,mid,qs,mid,st,si*2+1);
    }
    else if( qs > mid)
    {
        //cout<<"Case 4"<<endl;
        return  find_rangeUntil(mid+1,se,qs,qe,st,si*2+2);//find_rangeUntil(mid+1,se,mid+1,qe,st,si*2+2);
    }
    else
    {
        //cout<<"Case 5"<<endl;
        tree lp,rp,result;
        lp = find_rangeUntil(ss,mid,qs,qe,st,si*2+1);
        rp = find_rangeUntil(mid+1,se,qs,qe,st,si*2+2);
//            find_rangeUntil(ss,mid,qs,mid,st,si*2+1);
//            find_rangeUntil(mid+1,se,mid+1,qe,st,si*2+2);

             result.sum = lp.sum + rp.sum;
             result.left = Max(lp.left, lp.sum + rp.left);
             result.right = Max(rp.right, rp.sum + lp.right);
             result.mx = Max2(lp.mx, lp.right+rp.left, rp.mx);
             //cout<<"result.sum= "<<result.sum<<"   , result.mx= "<<result.mx<<endl;
             return result;

    }
}
/**
25
1 2 3 4 5 6 7 8 9 10 6 7 8 9 10 7 8 9 10 6 7 8 9 10 147
10
2 6
10 17
1 20
3 27
1 25
6 18
4 24
1 11
3 23
5 25
*/
/**
5
3 -1 -1 3 10
1
1 5
*/
