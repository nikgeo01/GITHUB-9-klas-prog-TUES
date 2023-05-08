#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode
{
    char *name;
    int priority;
    int state;
    struct ListNode *next;
};
typedef struct
{
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int priority);

void push(LinkedList *list, int index, double value, char *name);
void pushback(LinkedList *list, double value, char *name);
void pushfront(LinkedList *list, double value);

double pop(LinkedList *list, int index);
double popfront(LinkedList *list);
double popback(LinkedList *list);

void set(LinkedList *list, int index, double value);

void release(LinkedList *list);

#endif