#include <stdio.h>

unsigned char lights = 237;
void turnOffLightsWithEvenNumber();
void printLights();
int main()
{
    printLights();
    turnOffLightsWithEvenNumber();
    printf("\n");
    printLights();
}

void printLights()
{
    for (int i = 0; i < 8; i++)
    {
        printf("light %d is %d\n", i + 1, (lights >> i) & 1);
    }
}
void turnOffLightsWithEvenNumber()
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 != 0)
        {
            lights &= ~(1 << i);
        }
    }
}