#include <stdio.h>
int main()
{

    int n,bin=0,br=1;
    scanf("%d",&n);
    bin=binary(n,bin,br);
    printf("%d",bin);

    return 0;
}
int binary (int n,int converted,int br)
{
    if(n==0){return converted;}
    else
    {
        converted+=(n%2)*br;
        binary(n/2,converted,br*10);
    }
}
