#include <bits/stdc++.h>
using namespace std;

int bit[20001];
void update(int n,int index,int val)
{
    index ++;
    while(index <= n )
    {
        bit[index] += val;
        index += (index & (-index));
    }
}
int query(int n,int index)
{
    int sum = 0;
    index++;
    while(index > 0)
    {
        sum += bit[index];
        index -= (index & (-index));
    }
    return sum;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans[n];
        memset(bit,0,sizeof(int)*(n+1));

        for(int i = 0; i<n; i++)
        {
            update(n,i,1);///Initially, all element have 1.
        }

        int cur,free,pos,s,mid,e;
        cur =0;
        free = n;
        for(int i = 1; i<=n; i++)
        {
            cur = (cur + i )%free;
            ///cout<<cur<<endl;
            ///Binary search:Find the position of (cur+1)'th 1 in bit array, if cur = 0, 0'th 1 in array is undefined.
            s = 0,e = n-1;
            while(s + 1 < e)
            {
                mid = (s+e)/2;
                if(query(n,mid) < (cur+1))
                {
                    s = mid;
                }
                else
                {
                    e = mid;
                }
            }
            if(query(n,s) == (cur+1))
            {
                pos = s;
            }
            else
            {
                pos = e;
            }///Binary search ends.
            //cout<<"pos = "<<pos<<endl;
            ans[pos] = i;
            update(n,pos,-1);///updating with -1 means,making
            ///internal BIT array array[pos]=(1 + (-1))= 0 and updating
            ///all coverer of pos.

            free--;
        }
        for(int v:ans)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/***
Problem : Read last line of problem statement carefully. You have to determine the pre-order of cards
,meaning the soln will be simulated like the steps described in problem. The soln is like a circle,so
after last position in array, next position starts at the beginning.
Lets, n = 5, initially:_ _ _ _ _ (all are free, 5 free place)

step 1: _ 1 _ _ _  travel = 1 place, position = 1(starting from 0, 4 free place).so, ans[1] = 1.

step 2: _ 1 _ _ 2  travel = 2, position = 3(starting from 0 & not considering used spaces, 3 free spaces).so, ans[3] = 2.

step 3: "3 1 _ _ 2" travel = 3, position = (3+travel)%free space = (3+3)%3 = 0, free space = 2, ans[0] = 3.

step 4:"3 1 4 _ 2 ", travel = 4, position = (0+4)%2 = 0, free space = 1, ans[2] = 4,cause 0'th free place = 2.

step 5: "3 1 4 5 2", travel = 5,position = (0+5)%1=0, free space = 0, ans[3] = 5,cause 0'th free place = 3.

I misunderstood : After placing a number at a position, we have to delete the position and rescale
the deck/array and rescale the position. To rescale the array: free positions --; To rescale
the position : Use modular arithmetic. Rescaled or new current position = position % updated free positions.
        free = n; cur = 0;
        for(int i = 1; i<=n; i++)
        {
            cur = (cur + i )%free;
            free--;
        }
Code above calculates correct position(in variable cur) at each step.
How mod works here? Ans: Let's say current_position is 3, free_positions is reduced to = 3,means
new deck/array is (0,1,2).
The position of current_position in now =  current_position % free_positions = 3%3 = 0.
The same modular math we use in 12 hour clock system.

Used BIT for determining remaining empty places. Initially, all internal-array of bit indexes are set to 1,meaning all places
are empty. When, a place/index is filled it becomes 0. BIT query is used for cumulative sum which is total
remaining empty places for an index.

As cumulative sum is sorted in ascending order, a Binary Search is used to find position'th 1 in the BIT internal
array which uses Query() of BIT. position'th 1 = position'th empty place. Hope you've got already, BIT internal
array is like solution array in term of position, and u know position'th element is i so put it onto the ans array.
**/
