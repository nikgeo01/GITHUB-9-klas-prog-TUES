#include "linkedlist.h"
#include "citizen.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode *createnode(Citizen value)
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
    list.head = NULL;
    list.size = 0;
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of bounds\n");
        exit(1);
    }
    struct ListNode *node = list->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}

void push(LinkedList *list, int index, Citizen value)
{
    if (index == 0)
    {
        pushfront(list, value);
        return;
    }
    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *newnode = createnode(value);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    list->size++;
}

void pushback(LinkedList *list, Citizen value)
{
    push(list, list->size, value);
}

void pushfront(LinkedList *list, Citizen value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

Citizen popfront(LinkedList *list)
{
    struct ListNode *node = list->head;
    Citizen value = node->value;
    list->head = node->next;
    free(node);
    list->size--;
    return value;
}

Citizen popback(LinkedList *list)
{
    return pop(list, list->size - 1);
}

Citizen pop(LinkedList *list, char EGN)
{
    if (list->size == 0)
    {
        printf("List is empty\n");
        exit(1);
    }
    if (list->head->value.EGN == EGN)
    {
        return popfront(list);
    }
    struct ListNode *prevnode = list->head;
    while (prevnode->next != NULL)
    {
        if (prevnode->next->value.EGN == EGN)
        {
            break;
        }
        prevnode = prevnode->next;
    }
    if (prevnode->next == NULL)
    {
        printf("EGN not found\n");
        exit(1);
    }
    struct ListNode *node = prevnode->next;
    Citizen value = node->value;
    prevnode->next = node->next;
    free(node);
    list->size--;
    return value;
}

void release(LinkedList *list)
{
    while (list->size > 0)
    {
        popback(list);
    }
}