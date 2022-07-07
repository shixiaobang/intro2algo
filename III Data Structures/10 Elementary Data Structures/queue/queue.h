#if !defined(QUEUE_H)
#define QUEUE_H

#include <stdbool.h>

typedef struct
{
    int *keys;
    int head;
    int tail;
    int size;
} queue;

// Initialize a queue of at most n – 1 elements
queue *queue_ctor(int n);

// Destroy a queue
int queue_dtor(queue **q);

// Test whether the queue is empty
bool queue_empty(const queue *q);

// Test whether the queue is full
bool queue_full(const queue *q);

// INSERT operation on a queue
int enqueue(queue *q, int key);

// DELETE operation on a queue, return the key value formerly at the head of the queue
int dequeue(queue *q);

#endif // QUEUE_H
