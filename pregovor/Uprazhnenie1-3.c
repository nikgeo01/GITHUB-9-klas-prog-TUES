#include <stdio.h>
int main()
{
    int arr[]= {1, 7, 3, 4, 9, 2};
    for(int i = 0; i < sizeof(arr)/4; i++)
    {
        for(int j = i+1; j < sizeof(arr)/4; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i = 0; i < sizeof(arr)/4; i++)
        {
            printf("%d ",arr[i]);
        }

}
