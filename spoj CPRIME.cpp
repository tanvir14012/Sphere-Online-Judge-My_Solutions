#include <bits/stdc++.h>
using namespace std;
bool prime[100000002>>1];
int a[5761456];
void Sieve(int n)
{
    int sqN = (int) sqrt(n);
    int count = 2;
    for(int i =3; i<= sqN; i+=2)
    {
        if(prime[i>>1] == false)
        {
            for(int j = i*i; j<=n; j+=(2*i))
            {
                prime[j>>1] = true;
            }
        }
    }
    a[1] = 2;
    for(int i = 3; i<=n; i+=2)
    {
        if(prime[i>>1] == false)
        {
            a[count++] = i;
        }
    }
}
int FloorBinarySearch(int n)
{
    int left,mid,right;
    left = 0;
    right = 5761455;
    while(left+1<right)
    {
        mid = (left+right)/2;
        if(a[mid]>n)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return left;
}
int main()
{
    int n,primes;
    double d;
    Sieve(100000000);
    while(scanf("%d",&n) == 1 && n != 0)
    {
        primes = FloorBinarySearch(n);
        d = (double)n/(double)log(n);
        d = fabs(primes - d);
        d = d/primes;
        d*=100;
        printf("%.1f\n",d);
    }
    return 0;
}
/**
Use Sieve to store primes upto 10^8 in an array only once, int arr[5761456] is sufficient.
Then use BinarySearch to get floor index of n from array arr .(you can start index from 1)
floor index of n = number of primes<=n.
**/
