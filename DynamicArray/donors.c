#include <stdio.h>
#include "dynamicarr.h"

int main()
{

    DynamicArray arr = init(1);
    while (1)
    {
        int option;
        printf("Choose an option:\n");
        printf("0. Exit\n");
        printf("1. Add new donor\n");
        printf("2. Remove donor\n");
        printf("3. Print donors\n");
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                printf("Exiting...\n");
                return 0;
            case 1:
                printf("Adding new donor...\n");
                int EGN;
                printf("Enter EGN: ");
                scanf("%d", &EGN);
                pushback(&arr, EGN);
                printf("Donor added successfully!\n");
                break;
            case 2:
                printf("Removing donor...\n");
                printf("Enter EGN: ");
                scanf("%d", &EGN);
                int index = findelement(&arr, EGN);
                removeelement(&arr, index);
                printf("Donor removed successfully!\n");
                break;
            case 3:
                printf("Printing donors...\n");
                printdynarr(&arr);
                break;
            default:
                printf("Invalid option\n");
        }
    }


    return 0;
}