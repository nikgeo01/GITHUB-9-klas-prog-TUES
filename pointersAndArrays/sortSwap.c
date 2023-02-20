#include <stdio.h>

void swap (int * a, int * b);
void sort (int * arr, int len);

int main()
{

    int arr[] = {1, 5, 3, 2, 4};
    int *parr = arr;
    sort(parr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
void swap (int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort (int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}