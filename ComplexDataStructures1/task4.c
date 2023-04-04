#include <stdio.h>
#define ARRAY_SIZE 10

union Numbers {
    long odd;
    short even;
};

int main()
{
    union Numbers arr[ARRAY_SIZE];

    for (int i = 1; i < ARRAY_SIZE; i += 2)
    {
        arr[i].odd = i;
        printf("%ld ", arr[i].odd);
    }

    for (int i = 0; i < ARRAY_SIZE; i += 2)
    {
        arr[i].even = i;
        printf("%hd ", arr[i].even);
    }

    return 0;
}
