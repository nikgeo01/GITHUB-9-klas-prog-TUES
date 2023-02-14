#include <stdio.h>

strhalf(char * str, char ** p);

int main()
{

    char str[5] = "abcde";
    char *ptr = str;
    char *p;
    strhalf(ptr, &p);
    
    return 0;
}
strhalf(char * str, char ** p)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str = str + 1;
    }
    *p = str + len / 2;
}