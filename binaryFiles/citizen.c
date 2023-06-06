#include "citizen.h"
#include <stdlib.h>

void printCitizen(Citizen *citizen)
{
    printf("EGN: %s\n", citizen->EGN);
    printf("Name: %s\n", citizen->name);
    printf("Age: %d\n", citizen->age);
    printf("Education: %s\n", citizen->education);
    printf("Wokring: %s\n", citizen->isWorking ? "Yes" : "No");
    printf("Married: %s\n", citizen->isMarried ? "Yes" : "No");
}