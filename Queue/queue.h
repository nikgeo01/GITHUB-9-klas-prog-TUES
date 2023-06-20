#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
    double value;
    struct QueueNode *next;
};

typedef struct
{
    int size;
    struct QueueNode *head;
} Queue;

Queue init();

void push(Queue *queue, double value);
double pop(Queue *queue);

// For homework
void release(Queue *queue);

#endif