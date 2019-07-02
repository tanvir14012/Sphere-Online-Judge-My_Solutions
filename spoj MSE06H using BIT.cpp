#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
    point()
    {
        x = y = 0;
    }
};
struct compare
{
    bool operator ()(const point &a, const point &b)
    {
        return ( (a.x < b.x) || (a.x == b.x && a.y<b.y) );
    }
};

class BIT
{
private:
    int* a;
    int sz;
public:
    BIT(int sz)
    {
        this->sz = sz;
        a = new int[sz+1];
        memset(a,0,sizeof(a[0])*(sz+1));
    }
    int getSum(int index)
    {
        int sum = 0;
        while(index > 0)
        {
            sum += a[index];
            index -= (index & (-index));
        }
        return sum;
    }
    void update(int index, int val)
    {
        while(index <= sz)
        {
            a[index] += val;
            index += (index & (-index));
        }
    }
    void free()
    {
        delete[] a;
    }
};


int main()
{
    int t,m,n,k,u,v;
    long long int inversion_count;
    scanf("%d",&t);
    for(int c = 1; c<=t; c++)
    {

        scanf("%d%d%d",&m,&n,&k);
        point a[k];
        for(int i = 0; i<k; i++)
        {
            scanf("%d%d",&a[i].x, &a[i].y);
        }
        sort(a,a+k,compare());
        ///a.x is sorted now in increasing order.

        inversion_count = 0;
        BIT q(n);
        for(int i = k-1; i >=0 ; i--)
        {
            q.update(a[i].y, 1);
            inversion_count += q.getSum(a[i].y-1);
        }
        q.free();
        printf("Test case %d: %lld\n",c,inversion_count);
    }
    return 0;
}
/***
A road(x,y) u can think x is on X-axis(x,0) and y is on Y-axis(0,y).
one road (x,y) will intersect other road (a,b) if  x < a && y > b (or) x > a && y < b.

Idea- If you follow brute force approach then for finding number of roads crossed by road#i ,
you will compare road#i with all the roads starting from road#i+1 to road#k (not starting from road
#1 otherwise crossings will get counted twice). Sum of counts for all the roads will be the final
answer. O(k^2),TLE.

Let's sort the roads array in increasing order of x value.
Now, for each road i,
crossings are those(index from 0 to n, != i) whose y value i.e. whose.y > i.y because array is already sorted, i.x < those.x.
Notice, it is called inversion on y value,see spoj INVRCNT.
If you count inversion and resort by MergeSort based on y value in ascending order
(small to big), you will get total inversions = total crossings.
Gotcha: In first sort, if x==x then sort based on y value in ascending to make
2nd merge sort working.

Use pen-paper for better understanding.
BIT : Inversion can be calculated also by BIT or fenwick tree. BIT input-array index should store 0 or 1, where
index = y value, 0 = not visited, 1 = visited.Initially, all = 0.
After first sort,
for(int  i= k-1; i >= 0; i--)
{
    update(a[i].y, 1);
    ans += sum (a[i].y - 1 );
}
How this works:
Problem input : 1
3 4 4
1 4
2 3
3 1
3 2

After first sort:
1 4
2 3
3 1
3 2
steps:
we start from last,
3 2, bit-internal-array[2] = 1, sum[0..1] = 0, ans = 0
3 1, bit-internal-array[1] = 1, sum[0..0] = 0, ans = 0
2 3, bit-internal-array[3] = 1, sum[0..2] = 1+1 = 2, ans = 2
1 4, bit-internal-array[4] = 1, sum[0..3] = 1+1+1=3, ans = 5
output = ans = 5.
**/

