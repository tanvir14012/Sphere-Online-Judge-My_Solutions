#include <bits/stdc++.h>
using namespace std;

struct value
{
    int d1,d2,d3,d4;
};
int r,c;
void Calculate(value &v,int mx,int my,int cx,int cy);
void show(value m,value c1,value c2);
int main()
{
    int t,mx,my,c1x,c1y,c2x,c2y;
    value m,c1,c2;
    scanf("%d%d%d",&r,&c,&t);

    while(t--)
    {
        scanf("%d%d%d%d%d%d",&mx,&my,&c1x,&c1y,&c2x,&c2y);
        Calculate(m,mx,my,mx,my);
        Calculate(c1,mx,my,c1x,c1y);
        Calculate(c2,mx,my,c2x,c2y);
        //show(m,c1,c2);
        if(m.d1 < c1.d1 && m.d1 < c2.d1)
        {
            cout<<"YES"<<endl;
        }
        else if(m.d2 < c1.d2 && m.d2 < c2.d2)
        {

            cout<<"YES"<<endl;
        }
        else if(m.d3 < c1.d3 && m.d3 < c2.d3)
        {

            cout<<"YES"<<endl;
        }
        else if(m.d4 < c1.d4 && m.d4 < c2.d4)
        {

            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }



    return 0;
}
void Calculate(value &v,int mx,int my,int cx,int cy)
{
    --mx;--my;--cx;--cy;
    v.d1 = abs(0-cx) + abs(my-cy);
    v.d2 = abs(cx-r-1) + abs(my-cy);
    v.d3 = abs(mx-cx) + abs(0-cy);
    v.d4 = abs(cy-c-1) + abs(cx-mx);
}
void show(value m,value c1,value c2)
{
    cout<<"d1:--(mouse,cat1,cat2)= "<<m.d1<<" "<<c1.d1<<" "<<c2.d1<<endl;
    cout<<"d2:--(mouse,cat1,cat2)= "<<m.d2<<" "<<c1.d2<<" "<<c2.d2<<endl;
    cout<<"d3:--(mouse,cat1,cat2)= "<<m.d3<<" "<<c1.d3<<" "<<c2.d3<<endl;
    cout<<"d4:--(mouse,cat1,cat2)= "<<m.d4<<" "<<c1.d4<<" "<<c2.d4<<endl;

}
