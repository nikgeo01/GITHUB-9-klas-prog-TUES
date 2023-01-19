#include <stdio.h>

static unsigned int bitstate;

void setbit(int num)
{
    bitstate |= (1 << num);
}
void unsetbit(int num)
{
    bitstate &= ~(1 << num);
}
void tooglebit(int num)
{
    bitstate ^= (1 << num);
}
int isbitset(int num)
{
    if(num < 0 || num >= 32)
    {
        return -1;
    }
    return (bitstate & (1 << num)) != 0;
}
int getbitstate()
{
    return bitstate;
}