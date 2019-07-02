#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{


    int test;

    cin>>test;
    while(test--)
    {
        unsigned int d;
        unsigned char *a;

        unsigned int j, n, q, z, t;

        int i,arr[101],f;

        double p;
        cin>>n;
        p = 0.0;
        for(j = 2; j <= n; j++)
        {
            p += log10(j);
            /// cout<<"test="<<log10(j)<<" ,p="<<p<<endl;
        }
        d = (int)p + 1;
        /// cout<<"Digits="<<d<<endl;
        a = new unsigned char[d];
        for (i = 1; i < d; i++)
            a[i] = 0; //initialize
        a[0] = 1;
        p = 0.0;
        for (j = 2; j <= n; j++)
        {
            q = 0;/// carry
            p += log10(j);///to maintains digit.
            z = (int)p + 1; /// number of digits of next multiplication result
            ///cout<<"p->z="<<p<<"::"<<z<<endl;
            for (i = 0; i < z/*NUMDIGITS*/; i++)
            {
                t = (a[i] * j) + q;
                q = (t / 10);///carry
                a[i] = (char)(t % 10);
            }

        }
        long long int cnt=0;
        for( i =0; i <=d-1; i++)
        {
            // cout << (int)a[i];
            if((int)a[i]==0)
            {
                ++cnt;
            }
            else
            {
                break;
            }
        }

        cout<<cnt<<endl;
        delete []a;
    }
    return 0;
}
