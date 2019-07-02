#include <bits/stdc++.h>
using namespace std;

int BIT[1025][1025];

void update(int x, int y, int range, int value)
{
    ++x; ++y; ///Index starts from 1
    int y1;
    while(x <= range)
    {
        y1 = y;
        while(y1 <= range)
        {
            BIT[x][y1] += value;
            y1 += (y1 & (-y1));
        }
        x += (x & (-x));
    }
}

int getSum(int x,int y)
{
    ++x; ++y; ///Index starts from 1
    int y1,result = 0;

    while(x > 0)
    {
        y1 =  y;

        while(y1 > 0)
        {
           result += BIT[x][y1];
           y1 -= (y1 & (-y1));
        }
        x -= (x & (-x));
    }
    return result;
}
int main()
{
    int t,n,x,y,value,x1,y1,max_x,max_y,min_x,min_y,indexValue,addValue,OA,OB,OC,OD,ans;
    char str[5],ch;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        memset(BIT,0,sizeof BIT);

        while(true)
        {

            getchar();
            scanf("%s",str);
            if(strcmp(str,"END") == 0)
            {
                break;
            }
            else if(strcmp(str,"SET") == 0)
            {
                scanf("%d%d%d",&x,&y,&value);
                indexValue = getSum(x,y) - getSum(x-1,y) - getSum(x,y-1) + getSum(x-1,y-1); ///Value at the original matrix(x,y).
                //cout<<"Original matrix'x Index Value[x][y] = "<<indexValue<<endl;
                addValue = value - indexValue; ///Value need to be added
                update(x,y,n,addValue);
            }
            else if(strcmp(str,"SUM") == 0)
            {
                scanf("%d%d%d%d",&x,&y,&x1,&y1);
                max_x = max(x,x1);
                max_y = max(y,y1);
                min_x = min(x,x1);
                min_y = min(y,y1);

                OA = getSum(min_x-1,min_y-1);
                OB = getSum(min_x-1,max_y);
                OC = getSum(max_x,max_y);
                OD = getSum(max_x,min_y-1);

                ans = OC-OB-OD+OA;
                //cout<<"Track:  "<<OA<<" "<<OB<<" "<<OC<<" "<<OD<<endl;
                printf("%d\n",ans);

            }
        }
    }
    return 0;
}

/**

|
| O(0,0)
|------------------------------------------------> y
|
|
|
|
|     A(min_x,min_y).
|     .--------------------------------.  B(min_x,max_y)
|     |                                |
|     |                                |
|     |                                |
|     |                                |
|     |                                |
|     |                                |
|     .                                . C(max_x,max_y)
|      --------------------------------
|     D(max_x,min_y)
|
V
x


Assumed Point O(0,0) as top left. Derived point A,B,C,D and SUM(x,y,x1,y1) according to the formula:
OC-OB-OD+OA .

*/
