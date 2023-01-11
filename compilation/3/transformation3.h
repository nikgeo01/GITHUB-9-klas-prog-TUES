#ifndef TRANS
#define TRANS

typedef struct 
{
    long result;
    char error[100];
}transformation;

transformation funcTrans (char *str);
#endif