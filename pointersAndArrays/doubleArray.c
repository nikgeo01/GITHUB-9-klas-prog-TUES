#include <stdio.h>
#define ROWS 3
void print (int *arr, int rows);

int main()
{

    int arr[ROWS][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int *p = &arr[0][0];
    print(p, ROWS);

    return 0;
}

void print (int *arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%-3d ", *(arr + i * 4 + j));
        }
        printf("\n");
    }

}