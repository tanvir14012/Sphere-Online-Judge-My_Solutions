#include <stdio.h>

int main()
{
    float input[3],base,cur;
    short point; //boolean
    int t,i,it;
    char ch;
    scanf("%d%*c",&t);
    char str[105];
    while(t--)
    {
        i = 0;
        base = 10.0;
        cur = 0;
        point = 0;
        gets(str);
        for(it = 0; it<strlen(str); it++)
        {
            ch = str[it];
            if(ch == 'e')
            {
                input[i] = cur;
                i++;
                base = 10.0;
                cur = 0;
                point = 0;
            }
            else if(ch == '.')
            {
                point = 1;
                base = 10.0;
            }
            else
            {
                if(point)
                {
                    cur += (ch-'0')/base;
                    base *= 10;
                }
                else
                {
                    cur = cur*10 + ch-'0';
                }
            }
        }
        input[2] = cur;
        //printf("%f : %f : %f\n", input[0],input[1], input[2]);
        input[0] = ceil(3.1415*input[0]*input[1]*sqrt(input[0]*input[0] + input[2]*input[2]));
        printf("%.0f\n", input[0]);
    }
    return 0;
}

/*
Lateral(side) surface area of a cone = pi * r * l where l = sqrt(r*r + h*h).
It is mainly a parsing problem.
*/
