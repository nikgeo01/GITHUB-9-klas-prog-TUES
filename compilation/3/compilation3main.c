#include<stdio.h>
#include"transformation3.h"

int main()
{
    char str[20];
    gets(str);
    transformation trans = funcTrans(str);
    printf("%ld\n", trans.result);
    printf("%s", trans.error);
    
    return 0;
}