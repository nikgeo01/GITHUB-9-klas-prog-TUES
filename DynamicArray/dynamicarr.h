#ifndef DYNAMICARR_H
#define DYNAMICARR_H

typedef struct
{
    int *buffer;
    unsigned int capacity;
    unsigned int size;
} DynamicArray;

DynamicArray init(int capacity);
void pushback(DynamicArray *arr, double value);
double popback(DynamicArray *arr);

void pushfront(DynamicArray *arr, double value);
double popfront(DynamicArray *arr);

void setelement(DynamicArray *arr, int index, double value);
double getelement(DynamicArray *arr, int index);
void removeelement(DynamicArray *arr, int index);
int findelement(DynamicArray *arr, int value);

void release(DynamicArray *arr);

#endif