#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newStudent(char ***students, int ***marks, int subjectsCount, char **subjects, int *studentsCount);
void print(char **students, int **marks, int subjectsCount, char **subjects, int studentsCount);
void freeMemory(char **students, int **marks, char **subjects , int subjectsCount, int studentsCount);

int main ()
{
    int subjectsCount;
    printf("Enter the number of subjects: ");
    scanf("%d", &subjectsCount);
    getchar();

    char **subjects = (char**)calloc(subjectsCount, sizeof(char*));
    
    for(int i = 0; i < subjectsCount; i++)
    {
        printf("Enter subject %d: ", i+1);
        subjects[i] = (char*) calloc(15, sizeof(char));
        fgets(subjects[i], 16, stdin);

        int len = strlen(subjects[i]);
        subjects[i][len-1] = '\0';
    }
    char **students = NULL;
    int **marks = NULL;
    int studentsCount = 0;

    while (1)
    {
        printf("Choose option:\n");
        int option;
        printf("1. New student\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            newStudent(&students, &marks, subjectsCount, subjects, &studentsCount);
            break;
        case 2:
            print(students, marks, subjectsCount, subjects, studentsCount);
            break;
        case 3:
            freeMemory(students, marks, subjects, subjectsCount, studentsCount);
            return 0;
        default:
            printf("Invalid option!");
            break;
        }
    }
    return 0;
}

void newStudent(char ***students, int ***marks, int subjectsCount, char **subjects, int *studentsCount)
{
    (*studentsCount)++;
    *students = (char**) realloc (*students, (*studentsCount) * sizeof(char*));
    (*students)[*studentsCount - 1] = (char*) calloc(15, sizeof(char));
    
    printf("Enter student name: ");
    fgets((*students)[*studentsCount - 1], 16, stdin);
    int len = strlen((*students)[*studentsCount - 1]);
    (*students)[*studentsCount - 1][len-1] = '\0';

    *marks = (int**) realloc (*marks, (*studentsCount) * sizeof(int*));
    (*marks)[*studentsCount - 1] = (int*) calloc(subjectsCount, sizeof(int));
    for (int i = 0; i < subjectsCount; i++)
    {
        printf("Enter the mark for %s: ", subjects[i]);
        scanf("%d", &((*marks)[*studentsCount - 1][i]));
    }
}


void print(char **students, int **marks, int subjectsCount, char **subjects, int studentsCount)
{
    printf("%-15s", " ");
    for (int i = 0; i < subjectsCount; i++)
    {
        printf("%-15s", subjects[i]);
    }
    printf("\n");
    for (int i = 0; i < studentsCount; i++)
    {
        printf("%-15s", students[i]);
        for (int j = 0; j < subjectsCount; j++)
        {
            printf("%-15d", marks[i][j]);
        }
        printf("\n");
    }
}

void freeMemory(char **students, int **marks, char **subjects, int subjectsCount, int studentsCount)
{
    for (int i = 0; i < studentsCount; i++) {
        free(marks[i]);
    }
    free(marks);

    for (int i = 0; i < studentsCount; i++) {
        free(students[i]);
    }
    free(students);

    for (int i = 0; i < subjectsCount; i++) {
        free(subjects[i]);
    }
    free(subjects);
}
