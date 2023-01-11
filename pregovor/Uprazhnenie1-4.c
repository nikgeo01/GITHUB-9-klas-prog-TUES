#include <stdio.h>
int main()
{

    int arr[]={1,2,5,7,8,10},n,lenght=sizeof(arr)/4;
    scanf("%d",&n);
    int result=binary(arr,n,lenght);
    printf("%d",result);

    return 0;
}
int binary (int arr[], int n, int lenght)
{
    int low=0, mid, high=lenght-1, found=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(n==arr[mid])
        {
            return mid;
        }
        else
            {
                if(n<arr[mid])
                {
                    high=mid-1;
                    mid=(low+high)/2;
                }
                else
                {
                 low=mid+1;
                 mid=(low+high)/2;
                }
            }
    }
    return found;
}

