#include <stdio.h>

#define DEBUG(VAR) printf("%s %d %s %d", #VAR, VAR, __FILE__, __LINE__)

int main()
{
    int var = 6;
    DEBUG(var);

    return 0;
}