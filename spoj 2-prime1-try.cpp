#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void same(int);
void creat(int);
vector< int>v;
int main()
{
    int a,b,c,i,root,temp;
    cin>>a;
    while(a--)
    {
        cin>>b>>c;
        if(b==c)
        {
            same(b);
            continue;
        }
        temp=b;

        if(b%2==0 )
        {
            if(b==2) {}
            else
            ++b;
        }

         if (b==1) {b=3;}

        if(temp==2||temp==1||temp==0)
        {
            cout<<2<<endl;
        }
        creat((int)sqrt(c));
        for(i=b; i<=c; i+=2)
        {
            int flag=1;
            root=(int)sqrt(i);
                for(decltype(v.size()) j=0; j!=v.size() && v[j]<=root ; ++j)
                {
                   if(i%v[j]==0)
                   {
                       flag=0;
                       break;
                   }
                }
                if(flag)
                {
                    cout<<i<<endl;
                    //++qqq;

                }
            }
//cout<<"total="<<qqq<<endl;
        cout<<endl;
        v.clear();

        }
    return 0;
}
void same(int n)
{
    if(n==1) return ;
    int rot=(int)sqrt(n);
    for(int i=3;i<=rot;i+=2)
    {
        if(n%i==0)
        {
            return ;
        }
    }
    cout<<n<<endl;
}

void creat(int n)
{

    const int h=n/2;
    int a[h+1],i,j;
    for( i=0;i<=h;i++)
    {
        a[i]=0;
    }

    int r=(int)sqrt(n);
    for(i=3;i<=r;i+=2)
    {
       if(a[i/2]==0)
       {
           for(j=i*i;j<=n; j+=2*i)
           {
               a[j/2]=1;
           }
       }
    }
     for(i=3; i<=n; i+=2)
    {
        if(a[i/2]==0)
        {
            v.push_back(i);
        }
    }
}

