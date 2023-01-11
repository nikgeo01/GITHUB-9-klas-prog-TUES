#include <stdio.h>

int main()
{

    int arr[2][3] = {{1, 7, 6}, {5, 2, 8}};

    for (int i = 0; i < 2; i++)//i<2 zashtoto i sa redovete
    {
        for (int j = 0; j < 3; j++)//j<3 zashtoto j sa colonite
        {
            if (arr[i][j] % 2 == 1)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }

    return 0;
}
