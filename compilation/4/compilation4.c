#include <stdio.h>
#include <math.h>

#define ARR_SIZE 5

int main()
{
    long arr[ARR_SIZE] = {1, 2, 3, 4, 5};

    for(int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = pow(arr[i],4);
    }
    for(int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}