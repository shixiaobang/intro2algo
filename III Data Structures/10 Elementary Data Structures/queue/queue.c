#include "queue.h"

#include <stdlib.h>

queue *queue_ctor(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->keys = (int *)malloc(sizeof(int) * size);

    q->head = 0;
    q->tail = 0;
    q->size = size;

    return q;
}

int queue_dtor(queue *q)
{
    free(q->keys);
    free(q);

    return 0;
}

bool queue_empty(const queue *q)
{
    if (q->head == q->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue_full(const queue *q)
{
    if (q->head == ((q->tail + 1) % q->size))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int enqueue(queue *q, int key)
{
    int full = queue_full(q);
    if (full)
    {
        return 1;
    }
    else
    {
        *(q->keys + q->tail) = key;
        q->tail = (q->tail + 1) % q->size;

        return 0;
    }
}

int dequeue(queue *q)
{
    int empty = queue_empty(q);
    if (empty)
    {
        return -1;
    }
    else
    {
        int x = *(q->keys + q->head);
        q->head = (q->head + 1) % q->size;

        return x;
    }
}
