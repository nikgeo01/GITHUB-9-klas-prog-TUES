#include <stdio.h>
#include "linkedList.h"

int main()
{
    LinkedList list;

    while(1)
    {
        printf("Choose option:\n");
        printf("0. Exit\n");
        printf("1. Add new task\n");
        printf("2. Print tasks\n");
        printf("3. Change task state\n");
        printf("4. Remove task\n");
        
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Adding...\n");
            printf("Enter priority:\n");
            int priority;
            scanf("%d", &priority);
            printf("Enter name:\n");
            char name[30];
            getchar();
            fgets(name, 30, stdin);

            if(priority > list.size)
            {
                pushback(&list, list.size + 1, name);
            }
            else
            {
                push(&list, priority - 1, priority, name);
            }
            printf("Added\n");
            break;
        case 2:
            printf("Printing...\n");
            for(int i = 0; i < list.size; i++)
            {
                struct ListNode *node = get(&list, i);
                printf("%d %s", node->priority, node->name);
                switch (node->state)
                {
                case 0:
                    printf(" New\n");
                    break;
                case 1:
                    printf(" In progress\n");
                    break;
                case 2:
                    printf(" Done\n");
                    break;
                default:
                    break;
                }
            }
            break;
        case 3:
            printf("Changing...\n");
            printf("Enter priority:\n");
            int priority2;
            scanf("%d", &priority2);

            struct ListNode *node = get(&list, priority2 - 1);
            printf("Enter new state:\n");
            int state;
            scanf("%d", &state);
            node->state = state;

            printf("Changed\n");
            break;
        case 4:
            printf("Removing...\n");
            printf("Enter priority:\n");
            int priority3;
            scanf("%d", &priority3);

            pop(&list, priority3 - 1);
            printf("Removed\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}