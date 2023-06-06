#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "book.h"

static struct ListNode *createnode(Book value)
{
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

LinkedList init()
{
    LinkedList list = {size : 0, head : NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    struct ListNode *currentnode = list->head;
    for (int i = 0; i < index; i++)
    {
        currentnode = currentnode->next;
    }
    return currentnode;
}

void pushfront(LinkedList *list, Book value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

void push(LinkedList *list, int index, Book value)
{
    if (index == 0)
    {
        pushfront(list, value);
    }
    else
    {
        struct ListNode *prevnode = get(list, index - 1);
        struct ListNode *newnode = createnode(value);
        newnode->next = prevnode->next;
        prevnode->next = newnode;
        list->size++;
    }
}

void pushback(LinkedList *list, Book value)
{
    push(list, list->size, value);
}

Book popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = nodetodelete->next;
    list->size--;

    Book result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

Book pop(LinkedList *list, int index)
{
    if (index == 0)
    {
        return popfront(list);
    }

    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *nodetodelete = prevnode->next;
    prevnode->next = nodetodelete->next;
    list->size--;

    Book result = nodetodelete->value;
    free(nodetodelete);
    return result;
}
Book popback(LinkedList *list)
{
    return pop(list, list->size - 1);
}

void set(LinkedList *list, int index, Book value)
{
    struct ListNode *node = get(list, index);
    node->value = value;
}

void foreach (LinkedList *list, Eacher eacher)
{
    struct ListNode *currentElement = list->head;
    int index = 0;
    while (currentElement != NULL)
    {
        eacher(index, currentElement->value);
        index++;
        currentElement = currentElement->next;
    }
}