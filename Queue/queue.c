#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static struct QueueNode *createnode(double value)
{
    struct QueueNode *newnode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

Queue init()
{
    Queue queue = {NULL, 0};
    return queue;
}

void push(Queue *queue, int index, double value)
{
    struct QueueNode *current = queue->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    struct QueueNode *newnode = createnode(value);
    newnode->next = current->next;
    current->next = newnode;
    queue->size++;
}

double pop(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue is empty \n");
        exit(1);
    }
    struct QueueNode *current = queue->head;
    queue->head = current->next;
    double value = current->value;
    free(current);
    queue->size--;
    return value;
}

void release(Queue *queue)
{
    while (queue->size > 0)
    {
        popback(queue);
    }
}