#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Enter two numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int *pa = &a;
    int *pb = &b;
    printf("the address of the pointer to a is %p and the value is %d\n", &pa, *pa);
    printf("The address of the pointer to b is %p and the value is %d\n", &pb, *pb);
}