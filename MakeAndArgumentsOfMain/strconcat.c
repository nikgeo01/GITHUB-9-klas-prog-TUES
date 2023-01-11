#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv)
{ 
    int len1 = strlength(argv[1]);
    int len2 = strlength(argv[2]);
    if(argc != 3 || len1 > 50 || len2 > 50)
    {
        printf("Invalid number of arguments or too many symbols used!");
    }
    else
    {
        printf("%s\n", strconcat(argv[1], argv[2]));
    }

    return 0;
}