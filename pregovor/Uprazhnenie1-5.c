#include <stdio.h>
#include <string.h>
char find (char *niz);
int main()
{

    char niz[]="Ivan";
    char largest=find(niz);
    printf("%c",largest);
    return 0;
}
char find (char *niz)
{
    char largest=niz[0];
    for(int i=1;i<strlen(niz);i++)
    {
        if(largest<niz[i])
        {
            largest=niz[i];
        }
    }
    return largest;
}

