#include <stdio.h>
#include "processes.h"
#include <limits.h>
#include <string.h>

int processescount = 0;
struct Process processes[MAX_PROCESSES];

static int nextprocessid()
{
    static unsigned int id = 1;
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
    struct Process newProcess;
    newProcess.id = nextprocessid();
    strcpy(newProcess.name, name);
    if (newProcess.id == 0)
    {
        printf("No more processes can be created\n");
    }
    else
    {
        processes[processescount] = newProcess;
        processescount++;
        printf("New process created with id %d and name '%s'\n", newProcess.id, newProcess.name);
    }
}
void stopprocess(int id)
{
    int DELindex;
    for (int i = 0; i < processescount; i++)
    {
        if (processes[i].id == id)
        {
            DELindex = i;
        }
    }
    for (int i = DELindex; i < processescount; i++)
    {
        processes[i] = processes [i+1];
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