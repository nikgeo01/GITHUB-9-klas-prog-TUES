#include <stdio.h>

int sortAndSum (int *arr, int size);
#define DEBUG

int main()
{
    
    int arr[6] = {1,4,2,6,7,3};
    int sum = sortAndSum(arr, 6);

    return 0;
}
int sortAndSum (int *arr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        if(i%3 == 0)
        {
            sum += arr[i];
        }
    }

    #ifdef DEBUG
    for(int i=0; i<size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    for(int i=0; i<size; i++)
    {
        if(i%3 == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    #endif
    return sum;
}