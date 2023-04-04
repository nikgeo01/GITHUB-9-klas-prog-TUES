#include <stdio.h>
#include <stdbool.h>


typedef struct {
    char name[50];
    char middlename[50];
    char surname[50];
    char email[50];
    char phone[50];
}Volunteer;

typedef struct {
    Volunteer volunteer;
    bool isParticipating;
}Answer;

typedef struct {
    char title[50];
    char description[200];
    struct {
        int day;
        int month;
        int year;
        int hour;
    }date;
    int numberOfAnswers; 
    Answer answers[100];
}Cause;

int main()
{
      
    Cause cause1;
    printf("Enter title: ");
    fgets(cause1.title, 50, stdin); 
    printf("Enter description: ");
    fgets(cause1.description, 200, stdin);
    printf("Enter date and hour separated by spaces: ");
    scanf("%d %d %d %d", &cause1.date.day, &cause1.date.month, &cause1.date.year, &cause1.date.hour);
    printf("Enter the number of answers: ");
    scanf("%d", &cause1.numberOfAnswers);  
    for(int i = 0; i < cause1.numberOfAnswers; i++)
    {
        printf("Enter name: ");
        scanf("%s", cause1.answers[i].volunteer.name);
        printf("Enter middlename: ");
        scanf("%s", cause1.answers[i].volunteer.middlename);
        printf("Enter surname: ");
        scanf("%s", cause1.answers[i].volunteer.surname);
        printf("Enter email: ");
        scanf("%s", cause1.answers[i].volunteer.email);
        printf("Enter phone: ");
        scanf("%s", cause1.answers[i].volunteer.phone);
        printf("Enter isParticipating: ");
        scanf("%d", &cause1.answers[i].isParticipating);
    }
    printf("Title: %s\n", cause1.title);
    printf("Description: %s\n", cause1.description);
    printf("Date: %d %d %d %d\n", cause1.date.day, cause1.date.month, cause1.date.year, cause1.date.hour);
    printf("Number of answers: %d\n", cause1.numberOfAnswers);
    for(int i = 0; i < cause1.numberOfAnswers; i++)
    {
        printf("Name: %s\n", cause1.answers[i].volunteer.name);
        printf("Middlename: %s\n", cause1.answers[i].volunteer.middlename);
        printf("Surname: %s\n", cause1.answers[i].volunteer.surname);
        printf("Email: %s\n", cause1.answers[i].volunteer.email);
        printf("Phone: %s\n", cause1.answers[i].volunteer.phone);
        printf("isParticipating: %d\n", cause1.answers[i].isParticipating);
    }

    Cause cause2;
    printf("Enter title: ");
    fgets(cause2.title, 50, stdin);
    printf("Enter description: ");
    fgets(cause2.description, 200, stdin);
    printf("Enter date and hour separated by spaces: ");
    scanf("%d %d %d %d", &cause2.date.day, &cause2.date.month, &cause2.date.year, &cause2.date.hour);
    printf("Enter the number of answers: ");
    scanf("%d", &cause2.numberOfAnswers);
    for(int i = 0; i < cause2.numberOfAnswers; i++)
    {
        printf("Enter name: ");
        scanf("%s", cause2.answers[i].volunteer.name);
        printf("Enter middlename: ");
        scanf("%s", cause2.answers[i].volunteer.middlename);
        printf("Enter surname: ");
        scanf("%s", cause2.answers[i].volunteer.surname);
        printf("Enter email: ");
        scanf("%s", cause2.answers[i].volunteer.email);
        printf("Enter phone: ");
        scanf("%s", cause2.answers[i].volunteer.phone);
        printf("Enter isParticipating: ");
        scanf("%d", &cause2.answers[i].isParticipating);
    }
    printf("Title: %s\n", cause2.title);
    printf("Description: %s\n", cause2.description);
    printf("Date: %d %d %d %d\n", cause2.date.day, cause2.date.month, cause2.date.year, cause2.date.hour);
    printf("Number of answers: %d\n", cause2.numberOfAnswers);
    for(int i = 0; i < cause2.numberOfAnswers; i++)
    {
        printf("Name: %s\n", cause2.answers[i].volunteer.name);
        printf("Middlename: %s\n", cause2.answers[i].volunteer.middlename);
        printf("Surname: %s\n", cause2.answers[i].volunteer.surname);
        printf("Email: %s\n", cause2.answers[i].volunteer.email);
        printf("Phone: %s\n", cause2.answers[i].volunteer.phone);
        printf("isParticipating: %d\n", cause2.answers[i].isParticipating);
    }
    

    return 0;
}