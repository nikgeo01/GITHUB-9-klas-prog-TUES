#include <stdio.h>

int x=1, y=2;
#define SWAP(A, B) A = A + B; \
                   B = A - B; \
                   A = A - B;
#define SORT(ARRAY, SIZE, TYPE, COMPARE) if(x COMPARE y == 1)                       \
                                         {                                          \
                                            for(int i=0; i<SIZE-1; i++)             \
                                            {                                       \
                                                for(int j=0; j<SIZE-i-1; j++)       \
                                                {                                   \
                                                    if(arr[j] > arr[j+1])           \
                                                    {                               \
                                                        SWAP(arr[j], arr[j+1]);     \
                                                    }                               \
                                                }                                   \
                                            }                                       \
                                         }else if(x COMPARE y == 0)                 \
                                         {                                          \
                                            for(int i=0; i<SIZE-1; i++)             \
                                            {                                       \
                                                for(int j=0; j<SIZE-i-1; j++)       \
                                                {                                   \
                                                    if(arr[j] < arr[j+1])           \
                                                    {                               \
                                                        SWAP(arr[j], arr[j+1]);     \
                                                    }                               \
                                                }                                   \
                                            }                                       \
                                         }                                          \

int main()
{
    int arr[10] = {1,4,2,6,7,3};
    SORT(arr, 6, typeof(arr), >);
    for(int i=0; i<6; i++)
    {
        printf("%d", arr[i]);                          
    }  

    return 0;
}