#include <stdio.h>

void length (char *p);

int main()
{
    char str[] = "abcde";
    char *ptr = str;
    length(ptr);

    return 0;
}
void length (char *p)
{
    int len = 0;
    while (*p != '\0')
    {
        len++;
        p = p + 1;
    }
    printf("the length of the string is: %d\n", len);
}