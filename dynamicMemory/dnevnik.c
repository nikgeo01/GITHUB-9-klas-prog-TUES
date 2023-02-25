#include <stdio.h>
#include <stdlib.h>

float average (float *marks, int n);
void addMark (float *marks, int *n);
void delete (float *marks, int *n);
void end (float *marks);

int main()
{  
    int marksCount;
    while (1)
    {
        printf("Enter the number of marks: ");
        scanf("%d", &marksCount);
        if(marksCount < 1)
        {
            printf("Enter a number greater than 0!\n");
        }
        else
        {
            break;
        }
    }
    
    
    float * marks = (float *)calloc(marksCount, sizeof(float));
    
    for (int i = 0; i < marksCount; i++)
    {
        printf("Enter mark %d: \n", i + 1);
        scanf("%f", &marks[i]);
    }
    while(1)
    {
        printf("Choose option:\n");
        printf("1: Average.\n");
        printf("2: Add.\n");
        printf("3: Delete.\n");
        printf("4: End.\n");
        int option;
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                float avr;
                avr = average(marks, marksCount);
                printf("The average is: %f\n", avr);
                break;
            case 2:
                addMark(marks, &marksCount);
                printf("Added.\n");
                break;
            case 3:
                if(marksCount == 0)
                {
                    printf("The number of marks entered is 0. Now you can only add marks.\n");
                    break;
                }
                else
                {
                    delete(marks, &marksCount);
                    printf("Deleted.\n");
                    break;
                }
            case 4:
                printf("Ended.");
                return 0;
            default:
                printf("Invalid option!\n");
                
        }
    }
    return 0;
}
float average (float *marks, int n)
{
    float avr, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(marks + i);
    }
    avr = sum / n;
    
    return avr;
}
void addMark (float *marks, int *n)
{
    if(marks[0] != 0)
    {
        marks = (float *)realloc(marks, (*n + 1) * sizeof(float));
        *n += 1;
    }
    printf("Enter the new mark: ");
    scanf("%f", &marks[*n - 1]);
}
void delete (float *marks, int *n)
{
    if(*n == 1)
    {
        marks[0] = 0;
        printf("All marks have been ");
    }
    else
    {
        marks = (float *)realloc(marks ,(*n - 1) * sizeof(float));
        *n -= 1;
    }
    
}
void end (float *marks)
{
    if (marks == NULL)
    {
        printf("Not enough memory!\n");
    }
    else
    {
        free(marks);
    }
}