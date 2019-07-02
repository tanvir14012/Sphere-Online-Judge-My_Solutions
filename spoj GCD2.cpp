#include <stdio.h>
#include <string.h>
char b[250];
int gcd(int a,int b);
int main()
{
    int t,a,n,temp,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&a,b);
        if(a == 0)
        {
            printf("%s\n",b);
        }
        else
        {
            n = strlen(b);
            ///The algorithm we use in division by pen-paper
            ///Huh , it looked to me unfamiliar!! But I know it & it is that.
            temp = 0;
            for(i = 0; i<n; i++)
            {
                temp = ((b[i]-'0')+(temp*10))%a; /// think w.r.to remainder, not quotient(vagshesh).
            }
            temp = gcd(a,temp);
            printf("%d\n",temp);
        }
    }
    return 0;
}
int gcd(int a,int b)
{
    int c;
    while(b != 0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
/**
Refer CLRS textbook and Theorem 31.9 states that,
gcd(b,a) = gcd(a , b%a) , you reduce the big string by (b%a) using pen-paper method.

Hence finding the gcd of numbers a and b is the same as finding gcd of a and b%a .

Now , here's the part to find b%a which is a bit tricky as b is a string
How do we do basic division . Say, I want to find 954 / 7. Take a piece of paper , perform this division operation 954/7 and you'll be able to understand easily.

1. First , I do 9/7 and get the remainder 2.
2. Then , I bring down the number 5 . So, the new number will be 25. 25/7 will give me a remainder of 4.
3. Bring down 4 . The new number is 44. Again , 44/7 will give me a remainder of 2.

LOGIC : Read the number digit-by-digit and maintain the remainder, if it looks strange
to you then, do 957/7 in pen-paper method ,called long division method.

For example, for 1234 % 7.
1 mod 7 = 1
12 mod 7 = (1 * 10 + 2) mod 7 = 5
123 mod 7 = (5 * 10 + 3) mod 7 = 4
1234 mod 7 = (4 * 10 + 4) mod 7 = 2
**/
