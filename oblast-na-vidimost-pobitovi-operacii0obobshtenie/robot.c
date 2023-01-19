#include <stdio.h>
#include "bitstate.h"

int main()
{

     while (1)
    {
        int option;
        printf("1. Turn on light\n2. Turn off light\n3. Switch light\n4. Print light state\n5. Print robot state\n6. Exit\n");
        scanf("%d", &option);
        int chosenBit;
        if(option < 5)
        {
            printf("Choose a light from 1 to 32 included: ");
            scanf("%d", &chosenBit);
            chosenBit--;
        }
    
        switch (option)
        {  
            case 1:
                setbit(chosenBit);
                break;
            case 2:
                unsetbit(chosenBit);
                break;
            case 3:
                tooglebit(chosenBit);
                break;
            case 4:
                printf("Light state: %d\n", isbitset(chosenBit));
                break;
            case 5:
                printf("Robot state: %d\n", getbitstate());
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
return 0;
}