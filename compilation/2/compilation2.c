#include<stdio.h>

int NOK(int x, int y)
{    
    
    for(int i = x > y ? x : y; i <= x*y; i++ )
    {
        if(i % x == 0 && i % y == 0)
        {
            return i;
        }
    }
}

int main()
{
    int a,b;
    scanf("%d %d", &a,&b);
    int leastCommonMultiple = NOK(a,b);
    printf("%d", leastCommonMultiple);

    return 0;
}