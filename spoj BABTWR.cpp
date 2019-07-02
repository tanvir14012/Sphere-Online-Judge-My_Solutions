#include <bits/stdc++.h>
using namespace std;

struct box
{
    int h,w,l;
};
bool compare(box a,box b)
{
    return (a.l*a.w)>=(b.l*b.w);
}
int boxStackingDp(box a[],int n)
{
    int first,second,third,mx;
    box boxes[3*n];
    int ans[3*n];

    for(int i = 0; i != n; i++)
    {
        first = i*3;
        second = i*3 + 1;
        third = i*3 + 2;

        if(a[i].l < a[i].w)
        {
             a[i].l = a[i].l^a[i].w;
             a[i].w = a[i].l^a[i].w;
             a[i].l = a[i].l^a[i].w;///swapped to make l>=w.
        }
        boxes[first] = a[i];

        boxes[second].h = a[i].l;
        boxes[second].l = max(a[i].h,a[i].w);
        boxes[second].w = min(a[i].h,a[i].w);

        boxes[third].h = a[i].w;
        boxes[third].l = max(a[i].l,a[i].h);
        boxes[third].w = min(a[i].l,a[i].h);

    }
    sort(boxes,boxes + (3*n),compare);

    for(int i = 0; i<3*n; i++)
    {
        ans[i] = boxes[i].h;
    }
    for(int i = 1; i<3*n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if((boxes[i].l<boxes[j].l && boxes[i].w<boxes[j].w) &&
               ans[i]< ans[j]+boxes[i].h)
            {
                ans[i] = ans[j]+boxes[i].h;
            }
        }
    }
    mx = 0;
    for(int i = 0; i<3*n; i++)
    {
        if(ans[i]>mx)
        {
            mx = ans[i];
        }
    }
    return mx;
}
int main()
{
    int n,ans;

    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
        {
            break ;
        }

        box a[n];

        for(int i = 0; i!=n; i++)
        {
            scanf("%d%d%d",&a[i].h,&a[i].w,&a[i].l);
        }
        ans = boxStackingDp(a,n);
        printf("%d\n",ans);
    }
    return 0;
}
/**
algorithm:Box stacking algorithm dp.
source:youtube:tusher roy,code:geeksforgeeks:a bit modified.
**/
