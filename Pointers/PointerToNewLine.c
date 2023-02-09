#include <stdio.h>
#include <string.h>

int main()
{

    char niz[10];
    fgets(niz, 10, stdin);
    char *ps;
    ps = strchr(niz, '\n');
    if (ps != NULL)
    {
        *ps = '\0';
    }
    printf("The string is %s\n", niz);

    return 0;
}