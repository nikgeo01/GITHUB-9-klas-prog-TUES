#include <stdio.h>

void strhalf(char * str, char ** p);

int main()
{
    char str[] = "abcde";
    char *p;
    strhalf(str, &p);
    printf("The second half of the string is:%s\n", p);
    
    return 0;
}
void strhalf(char * str, char ** p)
{
    char *pstr;
    int len = 0;
    for (pstr = str; *pstr != '\0'; pstr++)
    {
        len++;
    }
    *p = str + len / 2;
}