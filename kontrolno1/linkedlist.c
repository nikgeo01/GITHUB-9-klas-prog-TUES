#include <stdio.h>
#include <stdlib.h>

struct Node
{
    long value;
    struct Node *next;
};

typedef struct LinkedList
{
    int size;
    struct Node *head;
} LinkedList;

LinkedList init(struct LinkedList *list)
{
    list->size = 0;
    list->head = NULL;
}

void createNode(struct LinkedList *list, long value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating a new node.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void popFront(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
}

struct Node *getNode(struct LinkedList *list, int index)
{
    if(index < 0 || index >= list->size)
    {
        return NULL;
    }
    struct Node *current = list->head;
    int i = 0;
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }
    if (i == index)
    {
        return current;
    }
}

void print(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("No values\n");
    }
    else
    {
        struct Node *current = list->head;
        for(int i=0; i<list->size; i++)
        {
            printf("%ld ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    struct LinkedList list;
    init(&list);

    createNode(&list, 1);
    createNode(&list, 5);
    createNode(&list, 7);
    print(&list);

    struct Node *node = getNode(&list, 1);
    printf("First index: %ld\n", node->value);
    

    popFront(&list);
    popFront(&list);
    print(&list);

    return 0;
}
