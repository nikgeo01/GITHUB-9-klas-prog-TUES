#include <stdio.h>

#define SWAP(A, B) A = A + B; \
                   B = A - B; \
                   A = A - B;
int main()
{
    char a = '2', b = '4';
    SWAP(a, b);
    printf("%c %c",a, b);
    return 0;
}