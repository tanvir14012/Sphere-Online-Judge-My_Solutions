#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
     int t;
     LL n;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%lld",&n);

               printf("%lld\n",(((n)*(n+2)*(2*n+1))/8));

     }

     return 0;
}
/**
The number of triangles is n*(n+2)*(2*n+1)/8.
**/
