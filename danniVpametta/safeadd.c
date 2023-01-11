#include <stdio.h>
#include "safeint.h"

void main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Invalid number of arguments!");
    }
    else
    {
        struct SafeResult xSafe = safestrtoint(argv[1]);
        struct SafeResult ySafe = safestrtoint(argv[2]);
        if (xSafe.errorflag == 1 || ySafe.errorflag == 1)
        {
            printf("Error: Overflow");
            return;
        }
        int x = xSafe.value;
        int y = ySafe.value;

        struct SafeResult result = safeadd(x, y);
        if (result.errorflag == 0)
        {
            printf("%d + %d = %d", x, y, result.value);
        }
        else
        {
            printf("Error: Overflow");
        }
    }
}