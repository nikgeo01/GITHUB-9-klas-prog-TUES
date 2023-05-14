#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode *createnode(double value)
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
    LinkedList list;
    list.size = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
    struct ListNode *current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current;
}

void push(LinkedList *list, int index, double value)
{
    if (index == 0)
    {
        pushfront(list, value);
        return;
    }
    if (index == list->size)
    {
        pushback(list, value);
        return;
    }
    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *newnode = createnode(value);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    list->size++;
}

void pushback(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    if (list->size == 0)
    {
        list->head = newnode;
    }
    else
    {
        list->tail->next = newnode;
    }
    list->tail = newnode;
    list->size++;
}

void pushfront(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    if (list->size == 0)
    {
        list->tail = newnode;
    }
    list->size++;
}

double pop(LinkedList *list, int index)
{
    if (index == 0)
    {
        return popfront(list);
    }
    if (index == list->size - 1)
    {
        return popback(list);
    }
    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *nodetodelete = prevnode->next;
    prevnode->next = nodetodelete->next;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);

    return result;
}

double popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = nodetodelete->next;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);

    return result;
}

double popback(LinkedList *list)
{
    struct ListNode *nodetodelete = list->tail;
    struct ListNode *current = list->head;
    while (current->next != nodetodelete)
    {
        current = current->next;
    }
    current->next = NULL;
    list->tail = current;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);

    return result;
}

void set(LinkedList *list, int index, double value)
{
    struct ListNode *current = get(list, index);
    current->value = value;
}

void release(LinkedList *list)
{
    struct ListNode *current = list->head;
    while (current != NULL)
    {
        struct ListNode *nodetodelete = current;
        current = current->next;
        free(nodetodelete);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}