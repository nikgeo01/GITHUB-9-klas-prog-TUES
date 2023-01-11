#include <stdio.h>
int lenght(int n){
    int size = 0;
    while(n!=0){
        size++;
        n/=10;
    }
    return size;
}
int main()
{
int a=417;
int pr=1;
for(int i=lenght(a); i!=0; i--)
{
    pr*=a%10;
    a/=10;
}
printf("%d\n",pr);

return 0;
}
