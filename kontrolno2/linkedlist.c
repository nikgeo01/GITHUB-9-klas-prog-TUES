#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    long value;
    int *next;
}

typedef struct
{
    int size;
    int *head;
} LinkedList;

LinkedList init(LinkedList *list)
{
    list->size = 0;
    list->head = NULL;
}

void createNode(LinkedList *list, long value)
{
    struct listNode newNode = *(struct listNode)malloc(sizeof(struct listNode));
    if (newNode == NULL)
    {
        printf("No memmory!");
    }
    else
    {
    }
}

void popFront(LinkedList *list)
{
    struct listNode *temp;
    temp = list->head;
    list->head =
}

void print(LinkedList *list)
{
    for(int i=0; i<list->size; i++)
    {
        printf("%ld", )
    }
}

int main()
{
    LinkedList list;
    init(&list);

    createNode(&list, 3)
        createNode(&list, 5)
            createNode(&list, 7)

                return 0;
}