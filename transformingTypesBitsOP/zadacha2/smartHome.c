#include <stdio.h>

int main()
{
    char rooms = 0;
    while (1)
    {
        int chooser;
        printf("\nEnter 1 to SwitchLights, 2 to PrintState or 3 to exit: ");
        scanf("%d", &chooser);

        if(chooser == 1)
        {
            int number;
            printf("Enter room number: ");
            scanf("%d", &number);

            rooms = rooms ^ (1 << (number - 1));
        }
        else if(chooser == 2)
        {
            printf("The light is on in rooms: ");
            
            for(int i = 0; i < 8; i++)
            {
                if (rooms & (1 << i))
                {
                    printf("%d ", i+1);
                }
            }
        }
        else
        {
            break;
        }
    }

  return 0;
}
