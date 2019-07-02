#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int temp=0,ans=0;
    for(int i=2; i<=100; ++i)
    {
        ans=(i*i*i);
        for(int j=2; j<i; ++j)
            for(int k=j+1; k<i; ++k)
                for(int l=k+1; l<i; ++l)
                {
                    temp=(j*j*j)+(k*k*k)+(l*l*l);
                    if(temp==ans)
                    {
                        cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
                        break;
                    }

                }
    }
    return 0;
}
