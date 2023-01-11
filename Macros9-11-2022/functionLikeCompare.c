#include <stdio.h>

#define MAX(x, y) printf("%d", x>y ? x:y)

int main()
{
    int a = 3, b = 5;
    MAX(a, b);

    return 0;
}