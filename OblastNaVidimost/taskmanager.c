#include <stdio.h>
#include "processes.h"

int main()
{
    while (1)
    {
        int option;
        printf("1. Create new process\n2. Print processes\n3. Stop process\n4. Exit\n");
        scanf("%d", &option);
        switch (option)
        {  
            case 1:
                if(processescount > 4)
                {
                    printf("The limit for active processes has been reached! Stop one of the active processes to create new.\n");
                }
                else
                {
                    printf("Enter process name: ");
                    char name[30];
                    scanf("%s", name);
                    createnewprocess(name);
                }
                break;
            case 2:
                printprocesses();
                break;
            case 3:
                printf("Enter process id: ");
                int id;
                scanf("%d", &id);
                stopprocess(id);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    
   
    return 0;
}