#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

typedef struct Node
{
    Book book;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    int size;
    Node *head;
} LinkedList;

void init(LinkedList *list)
{
    list->size = 0;
    list->head = NULL;
}

void add(LinkedList *list, Book book)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->book = book;
    node->next = NULL;

    if (list->size == 0)
    {
        list->head = node;
    }
    else
    {
        Node *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->size++;
}

void print(LinkedList *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%s %s %d %s %s\n", temp->book.bookName, temp->book.genre, temp->book.yearPublished, temp->book.authorName, temp->book.ISBN);
        temp = temp->next;
    }
}

void saveToFile(LinkedList *list)
{
    FILE *LibraryFile = fopen("Library.txt", "w");
    if (LibraryFile == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    Node *temp = list->head;
    while (temp != NULL)
    {
        fprintf(LibraryFile, "%s %s %d %s %s\n", temp->book.bookName, temp->book.genre, temp->book.yearPublished, temp->book.authorName, temp->book.ISBN);
        temp = temp->next;
    }
    fclose(LibraryFile);
}



int main()
{
    LinkedList list;

    FILE *file = fopen("Library.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];

    while (fgets(line, 100, file) != NULL)
    {
        Book *book = (Book *)malloc(sizeof(Book));
        if (book == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        book->ISBN = atoi(token);
        token = strtok(NULL, ",");
        book->name = (char *)malloc(strlen(token) + 1);
        if (book->name == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->name, token);
        token = strtok(NULL, ",");
        book->authorName = (char *)malloc(strlen(token) + 1);
        if (book->authorName == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->authorName, token);
        token = strtok(NULL, ",");
        book->genre = (char *)malloc(strlen(token) + 1);
        if (book->genre == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        strcpy(book->genre, token);
        token = strtok(NULL, ",");
        book->year = atoi(token);
        pushback(&list, book);
    }

    
    printf("\n\n");
    printf("Choose option:\n");
    printf("0. Save changes and exit\n");
    printf("1. Add a book\n");
    printf("2. Print all books\n");
    printf("3. Delete book\n");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 0:
        printf("Saving changes and exiting...\n");
        break;
    case 1:
        printf("Adding a book...\n");
        fopen("Library.txt", "a");

        printf("Enter book name: ");
        char bookName[100];
        scanf("%s", bookName);
        printf("Genre: ");
        char genre[100];
        scanf("%s", genre);
        printf("Year published: ");
        int yearPublished;
        scanf("%d", &yearPublished);
        printf("Enter author name: ");
        char authorName[100];
        scanf("%s", authorName);
        printf("Enter ISBN: ");
        char ISBN[100];
        scanf("%s", ISBN);

        Book *newBook;
        strcpy(newBook->bookName, bookName);
        strcpy(newBook->genre, genre);
        newBook->yearPublished = yearPublished;
        strcpy(newBook->authorName, authorName);
        strcpy(newBook->ISBN, ISBN);

        add(&list, *newBook);

        fprintf(LibraryFile, "%s %s %d %s %s\n", bookName, genre, yearPublished, authorName, ISBN);

        break;
    case 2:
        printf("Printing all books...\n");
        break;
    case 3:
        printf("Deleting a book...\n");
        break;
    }

    return 0;
}