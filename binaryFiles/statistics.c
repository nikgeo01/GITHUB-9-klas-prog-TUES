#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citizen.h"
#include "linkedlist.h"

void readCitizen(FILE *file, Citizen *citizen)
{
    fread(citizen->EGN, sizeof(char), 11, file);
    fread(citizen->name, sizeof(char), 255, file);
    fread(&citizen->age, sizeof(unsigned short), 1, file);
    fread(&citizen->education, sizeof(unsigned char), 1, file);
    fread(&citizen->isWorking, sizeof(unsigned char), 1, file);
    fread(&citizen->isMarried, sizeof(unsigned char), 1, file);
}
void writeCitizen(FILE *file, Citizen *citizen)
{
    fwrite(citizen->EGN, sizeof(char), 11, file);
    fwrite(citizen->name, sizeof(char), 255, file);
    fwrite(&citizen->age, sizeof(unsigned short), 1, file);
    fwrite(&citizen->education, sizeof(unsigned char), 1, file);
    fwrite(&citizen->isWorking, sizeof(unsigned char), 1, file);
    fwrite(&citizen->isMarried, sizeof(unsigned char), 1, file);
}

int main(int argc, char const *argv[])
{
    FILE *citizenFile = fopen(argv[1], "ab+");
    if (citizenFile == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    LinkedList list = init();
    while(1)
    {
        Citizen citizen;
        readCitizen(citizenFile, &citizen);
        if (feof(citizenFile))
        {
            break;
        }
        pushback(&list, citizen);
    }

    while(1)
    {
        printf("Choose option:\n");
        printf("0. Exit\n");
        printf("1. Add citizen\n");
        printf("2. Remove citizen\n");
        printf("3. Print all citizens\n");

        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            
            struct ListNode *current = list.head;
            while (current != NULL)
            {
                writeCitizen(citizenFile, &current->value);
                current = current->next;
            }

            release(&list);
            return 0;
        case 1:
            printf("Enter EGN:\n");
            char EGN[11];
            scanf("%s", EGN);
            printf("Enter name:\n");
            char name[255];
            scanf("%s", name);
            getchar();
            printf("Enter age:\n");
            unsigned short age;
            scanf("%hu", &age);
            getchar();
            printf("Choose education:\n");
            printf("1. none\n");
            printf("2. Primary\n");
            printf("3. Secondary\n");
            printf("4. Higher\n");
            int  educationOption;
            scanf("%d", &educationOption);
            unsigned char education = 1;
            education = education << (educationOption - 1);
            printf("Is working:\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int isWorkingOption;
            scanf("%d", &isWorkingOption);
            unsigned char isWorking = isWorkingOption == 1 ? 1 : 0;
            printf("Is married:\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int isMarriedOption;
            scanf("%d", &isMarriedOption);
            unsigned char isMarried = isMarriedOption == 1 ? 1 : 0;
            
            Citizen citizen;
            strcpy(citizen.EGN, EGN);
            strcpy(citizen.name, name);
            citizen.age = age;
            citizen.education = education;
            citizen.isWorking = isWorking;
            citizen.isMarried = isMarried;

            pushback(&list, citizen);

            break;
        case 2:
            printf("Enter EGN:\n");
            int EGNToRemove;
            scanf("%d", &EGNToRemove);
            Citizen citizenToRemove = pop(&list, EGNToRemove);
            printf("Removed citizen:\n");
            printCitizen(&citizenToRemove);
            break;
        
        case 3:
            for (int i = 0; i < list.size; i++)
            {
                Citizen *citizen = get(&list, i);
                printCitizen(citizen);
            }
            {

            }
            
            
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    fclose(citizenFile);

    return 0;
}