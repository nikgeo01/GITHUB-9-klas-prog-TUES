#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode
{
    Citizen value;
    struct ListNode *next;
};

typedef struct
{
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, Citizen value);
void pushback(LinkedList *list, Citizen value);
void pushfront(LinkedList *list, Citizen value);

Citizen pop(LinkedList *list, char EGN);
Citizen popfront(LinkedList *list);
Citizen popback(LinkedList *list);

// For homework
void release(LinkedList *list);

#endif