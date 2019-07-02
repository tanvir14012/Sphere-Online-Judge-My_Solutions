#include <stdio.h>
#include <string.h>

char str[10000000];
int carryFlag = 0;

void increamentByOne(int pos )// Adds one to the number at digit position pos i.e. str(0...pos ) + 1
{
    int carry = 1, x;
    while(pos >= 0 )
    {
        x = (str[pos] - '0') + carry;
        carry = x / 10;
        x = x%10;
        str[pos] = x + '0';
        pos--;
    }
    if(carry == 1 && pos == -1)
    {
        carryFlag = 1;
    }

}
void swap(int pos, int n)
{
    int i;
    for(i = pos; i >= 0; i--)
    {
        str[n-1-i] = str[i];
    }
}


int main()
{
    int t, n, leftMid, middle, rightMid, temp;
    scanf("%d%*c",&t);
    while(t--)
    {
        gets(str);
        n = strlen(str);
        if(n & 1) //Odd
        {
            rightMid = n/2 + 1;
            middle = rightMid - 1;
            leftMid = rightMid - 2;

            if(str[leftMid] < str[rightMid])
            {
                increamentByOne(middle);
            }
            else if(str[leftMid] == str[rightMid])
            {
                while(leftMid >= 0 && str[leftMid] == str[rightMid])
                {
                    leftMid--;
                    rightMid++;
                }
                if(leftMid < 0 || str[leftMid] < str[rightMid])
                {
                    increamentByOne(middle);
                }
            }
            swap(middle, n);
        }
        else //Even
        {
            rightMid = n/2;
            leftMid = rightMid - 1;
            temp = leftMid;
            if(str[leftMid] < str[rightMid])
            {
                increamentByOne(leftMid);
                swap(leftMid, n);
            }
            else if(str[leftMid] == str[rightMid])
            {
                while(leftMid >= 0 && str[leftMid] == str[rightMid])
                {
                    leftMid--;
                    rightMid++;
                }
                if(leftMid == 0) /// 10000  or 9330 or 1339
                {
                    if(str[0] == '1' && str[n-1] == '0')
                    {
                        str[n-1] = '1';
                    }
                    else
                    {
                        if(str[leftMid] < str[rightMid]) /// 1339
                        {
                            increamentByOne(temp);
                            swap(temp, n);
                        }
                        else /// 9330
                        {
                            swap(temp, n);
                        }
                    }
                }
                else if(leftMid == -1) /// 9999s or 1111
                {
                    increamentByOne(temp);
                    swap(temp, n);
                }
                else if(str[leftMid] < str[rightMid])
                {
                    increamentByOne(temp);
                    swap(temp, n);
                }
                else
                {
                    swap(temp, n);
                }
            }
            else
            {
                swap(leftMid, n);
            }
        }
        if(carryFlag == 1)
        {
            str[n-1] = '1';
            printf("1");
        }
        printf(str);
        printf("\n");
        carryFlag = 0;
    }
    return 0;
}
