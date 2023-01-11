#include<stdio.h>
#include"transformation3.h"
#include<string.h>

transformation funcTrans(char *str)
{
    transformation trans;

    int flag = 1;
    int i = 0;
    int negative = 0;
    if (str[0] == '-')
    {
        i = 1;
        negative = 1;
    }
    while(i < strlen(str))
    {
        
        if(str[i]-'0' >= 0 && str[i]-'0' <= 9)
        {
            i++;
            continue;
        }
        else
        {
            flag = 0;
        }

        i++;
    }

    
    if(flag)
    {
        trans.result = 0;
        if(negative)
        {
            for(i=1; i<strlen(str); i++)
            {
		        trans.result = trans.result*10 + (str[i] - '0');
	        }
            trans.result *= -1;
        }
        else
        {
            for(i=0; i<strlen(str); i++)
            {
		        trans.result = trans.result*10 + (str[i] - '0');
	        } 
        }
        strcpy(trans.error,"");
    }
    else
    {
        trans.result = 0;
        strcpy(trans.error,"Invalid input string");
    }
    
    return trans;
}