#include <stdio.h>

int compareasc(void *a, void *b);
int comparedesc(void *a, void *b);

int main()
{

    int a = 10;
    int b = 20;
    void *pa = &a;
    void *pb = &b;
    int result1 = compareasc(pa, pb);
    int result2 = comparedesc(pa, pb);
    printf("The result of compareasc of a and b is %d\n", result1);
    printf("The result of comparedesc of a and b is %d\n", result2);

    return 0;
}

int compareasc(void *a, void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparedesc(void *a, void *b)
{
    if (*(int *)a < *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a > *(int *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}