#include <stdio.h>

void bubblesort (int *arr, int len, int (*compare)(void *, void *));
int compareasc(void *a, void *b);
int comparedesc(void *a, void *b);

int main()
{
    int arr[5] = {2, 3, 5, 1, 7};
    int len = 5;

    bubblesort(arr, len, compareasc);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubblesort(arr, len, comparedesc);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubblesort (int *arr, int len, int (*compare)(void *, void *))
{

    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1; j++)
        {
            if (compare(&arr[j], &arr[j+1]) > 0)
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}
int compareasc(void *a, void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparedesc(void *a, void *b)
{
    if (*(int *)a < *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a > *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}