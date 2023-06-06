#ifndef BOOK
#define BOOK

typedef struct
{
    int ISBN;
    char *title;
    char *author;
    char *genre;
    int year;
} Book;

void printBook(Book *book);

#endif