#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        printf("%d", strlength(argv[1]));
    }
    else
    {
        printf("Invalid number of arguments!");
    }
    

    return 0;
}