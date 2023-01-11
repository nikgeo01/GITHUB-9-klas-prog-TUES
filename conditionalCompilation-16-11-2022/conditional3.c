#include <stdio.h>

#define ARRAY_SIZE 6
void sort(int *arr, int size);
int main()
{

#ifdef ARRAY_SIZE

    #if ARRAY_SIZE > 0 && ARRAY_SIZE < 10
        int arr[ARRAY_SIZE] = {5, 1, 7, 2, 8, -12};

        sort(arr, ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            printf("%d\n", arr[i]);
        }

    #else
        printf("Unsupported array size!");
    #endif

#else
    printf("Unsupported array size!");
#endif

    return 0;
}
void sort(int *arr, int size)
{

    #ifdef _WIN32
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
    #elif defined __linux__

        for (int i=0; i<size-1; i++)
        {
            int min_idx = i;
            for (int j=i+1; j<size; j++)
            {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            }

            if(min_idx != i)
            {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }

    #elif defined __APPLE__

        int  key;
        for (int i=1; i<size; i++)
        {
            key = arr[i];
            j = i-1;

            while (int j >= 0 && arr[j] > key)
            {
                arr[j +1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }

    #else
        int arr1[size];
        for(int i=0; i<size; i++)
        {
            arr1[i] = arr[i];
        }
        for(int i=0; i<size; i++)
        {
            arr[size-i] = arr1[i];
        }
    #endif

}
