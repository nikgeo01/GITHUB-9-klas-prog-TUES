#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"


void serializeEmployee(FILE *file, struct Employee *employee)
{
    fwrite(employee->name, sizeof(char), sizeof(employee->name), file);
    fwrite(&(employee->numEmployees), sizeof(int), 1, file);
    for (int i = 0; i < employee->numEmployees; i++)
    {
        serializeEmployee(file, employee->employees[i]);
    }
}

void deserializeEmployee(FILE *file, struct Employee **employee)
{
    *employee = (struct Employee *)malloc(sizeof(struct Employee));
    fread((*employee)->name, sizeof(char), sizeof((*employee)->name), file);
    fread(&((*employee)->numEmployees), sizeof(int), 1, file);
    (*employee)->employees = (struct Employee **)malloc((*employee)->numEmployees * sizeof(struct Employee *));
    for (int i = 0; i < (*employee)->numEmployees; i++)
    {
        deserializeEmployee(file, &((*employee)->employees[i]));
    }
}

void printHierarchy(struct Employee *employee, int step)
{
    for (int i = 0; i < step; i++)
    {
        printf("  ");
    }
    printf("%s\n", employee->name);
    for (int i = 0; i < employee->numEmployees; i++)
    {
        printHierarchy(employee->employees[i], step + 1);
    }
}

int main()
{

    struct Employee employee1 = {"John", 0, NULL};
    struct Employee employee2 = {"Mary", 0, NULL};
    struct Employee employee3 = {"Peter", 0, NULL};
    struct Employee employee4 = {"Paul", 0, NULL};
    struct Employee employee5 = {"Jack", 0, NULL};
    struct Employee employee6 = {"Jill", 0, NULL};

    struct Employee manager1 = {"Tom", 3, NULL};
    struct Employee **employeeArray1 = malloc(manager1.numEmployees * sizeof(struct Employee *));
    employeeArray1[0] = &employee1;
    employeeArray1[1] = &employee2;
    employeeArray1[2] = &employee3;
    manager1.employees = employeeArray1;

    struct Employee manager2 = {"Jerry", 3, NULL};
    struct Employee **employeeArray2 = malloc(manager2.numEmployees * sizeof(struct Employee *));
    employeeArray2[0] = &employee4;
    employeeArray2[1] = &employee5;
    employeeArray2[2] = &employee6;
    manager2.employees = employeeArray2;

    struct Employee director = {"Bob", 2, NULL};
    struct Employee **managerArray = malloc(director.numEmployees * sizeof(struct Employee *));
    managerArray[0] = &manager1;
    managerArray[1] = &manager2;
    director.employees = managerArray;

    FILE *file = fopen("employees.bin", "wb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    serializeEmployee(file, &director);
    fclose(file);

    struct Employee *deserializedDirector = NULL;
    file = fopen("employees.bin", "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    deserializeEmployee(file, &deserializedDirector);
    fclose(file);

    printHierarchy(deserializedDirector, 0);

    free(deserializedDirector->employees);
    free(deserializedDirector);

    return 0;
}
