#include <stdio.h>
#include "mystrings.h"

int strlength(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char *strconcat(char *str1, char *str2)
{
    int length = 0, j;
    while (str1[length] != '\0')
    {
        length++;
    }

    for (j=0; str2[j] != '\0'; j++, length++)
    {
        str1[length] = str2[j];
    }
    str1[length] = '\0';
    return str1;
}

int strcompare(char *str1, char *str2)
{
    int str1Len = strlength(str1);
    int str2Len = strlength(str2);

    if (str1Len == str2Len)
    {
        for (int i=0; i<str1Len; i++)
        {
            if(str1[i] < str2[i])
            {
                return -1;
            }
            else 
            {
                if(str1[i] > str2[i])
                {
                    return 1;
                }
            }
            return 0;
        }
    }

    int strOneIsLonger = str1Len>str2Len ? 1:0;
    str1Len = str1Len<str2Len ? str1Len:str2Len;
    for (int i=0; i<str1Len; i++)
    {
        if(str1[i] < str2[i])
        {
            return -1;
        }
        else
        { 
            if(str1[i] > str2[i])
            {
                return 1;
            }
        }
    }
    if(strOneIsLonger)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}