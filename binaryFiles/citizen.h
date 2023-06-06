#ifndef CITIZEN_H
#define CITIZEN_H

typedef struct
{
    char EGN[11];
    char name[255];
    unsigned short age;
    unsigned char education;
    unsigned char isWorking;
    unsigned char isMarried;
} Citizen;

void printCitizen(Citizen *c);

#endif