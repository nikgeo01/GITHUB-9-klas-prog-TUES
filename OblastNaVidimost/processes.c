#include <stdio.h>
#include "processes.h"
#include <limits.h>
#include <string.h>


static int nextprocessid()
{
    static unsigned int id = 0;
    if (id == UINT_MAX)
    {
        return 0;
    }
    else
    {
        return id++;
    }
}
void createnewprocess(char *name)
{
    processescount++;
    processes[processescount].id = nextprocessid();
    if (processes[processescount].id == 0)
    {
        printf("No more processes can be created");
        processescount--;
    }
    else
    {
        strcpy(processes[processescount].name, name);
        printf("New process created with id %d and name '%s'", processes[processescount].id, processes[processescount].name);
    }
}
void stopprocess(int id)
{
    int DelIndex;
    for (int i = 0; i < processescount; i++)
    {
        if (processes[i].id == id)
        {
            DelIndex = i;
        }
    }
    if (DelIndex < processescount)
    {
        struct Process temp;
        temp = processes[processescount];
        processes[processescount] = processes[DelIndex];
        processes[DelIndex] = temp;
    }
    processescount--;
}
void printprocesses()
{
    for (int i = 0; i < processescount; i++)
    {
        printf("Process with id %d and name '%s' is active\n", processes[i].id, processes[i].name);
    }
}