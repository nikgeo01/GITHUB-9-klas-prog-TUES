#include <stdio.h>
int main()
{

int arr[]={1,7,10,15,16,13,23,30};

int sum=0;
for(int i=0; i<sizeof(arr)/4; i++)//sizeof се дели на 4 защото брои броя на байтовете
{
    int temp=0;
    for(int j=2;j<arr[i];j++)
    {
        if(arr[i]%j==0)temp++;

    }
    if(temp==0 && arr[i]>=2)
    {
        sum+=arr[i];
    }
}
printf("%d\n",sum);

return 0;
}
