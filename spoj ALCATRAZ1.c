#include <stdio.h>

int main()
{
    int t,i;
    unsigned long long int sum = 0;
    char str[64];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s", str);
        for(i = 0; i< strlen(str); i++)
        {
            sum += str[i] - 48;
        }
        printf("%llu\n", sum);
        sum = 0;
    }
    return 0;
}
