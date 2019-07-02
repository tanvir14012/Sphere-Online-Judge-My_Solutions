#include <bits/stdc++.h>
using namespace std;


#define pi 3.14159265358979323846264338327950
bool _checker_(double *a,int  n,double mid, int  f);

int main()
{
    int  t;
    scanf("%d",&t);
    while(t--)
    {
        int  p,f;
        scanf("%d%d",&p,&f);
        ++f; //because friends+myself also.
        double *a=new double[p];
        for(size_t i=0; i<p; i++)
        {
            scanf("%lf",&a[i]);
            a[i]*=a[i]*pi;
        }

        sort(a,a+p);
        double start,mid,end;
        start=0;
        end=a[p-1];

        while(start+.0000001 <= end)
        {
            mid=(start+end)/2.00;
            if((_checker_(a,p,mid,f))==true)
            {
                start=mid;
            }
            else
            {
                end=mid;
            }
        }

        //printf("%.4lf\n",start);
        cout<<setprecision(4)<<fixed<<start<<endl;
        delete [] a;
    }
}

bool _checker_(double *a,int  n,double mid, int  f)
{
    if(mid==0)
    {
        return 0;
    }
    int  ct=0;

    for(size_t i=0; i<n; i++)
    {
        ct+=(int ) (a[i]/mid) ;
        //cout<<"ct_______="<<a[i]/mid<<endl;
    }

    if(ct>=f)
    {
        return true;
    }
    return false;
}

/***
I used bidirectional property of binary search which is applied to volume of all given radii by (start,mid,end as volume too).
for example: if mid=50.55 satisfies any (int)f+1 volume then look for (mid-end) otherwise(start-mid).
if(any volume/mid(as volume too) >= 1.0 it satisfies 1 guy.
_checker_ returns true if  the mid(volume) satisfies at least f guys.
*/
