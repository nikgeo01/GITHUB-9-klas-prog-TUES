#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_NAME_LENGTH 30
#define MAX_PROCESSES 5

struct Process
{
    int id;
    char name[MAX_NAME_LENGTH];
};

extern struct Process processes[MAX_PROCESSES];
int processescount = 0;

void createnewprocess();
void stopprocess();
void printprocesses();

#endif