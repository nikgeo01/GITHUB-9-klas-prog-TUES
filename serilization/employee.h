#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee{
    char name[100];
    int numEmployees;
    struct Employee **employees;
};

#endif 