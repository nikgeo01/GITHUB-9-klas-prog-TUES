#include <stdio.h>

#define ARRAY int arr[5] = {1, 2, 3, 4, 5};
#define PRINTARRAY for(int i=0; i<5; i++) \
                    { \
                        printf("%d", arr[i]); \
                    }
int main()
{
    ARRAY
    PRINTARRAY
    return 0;
}