#include "deque.h"
#include <math.h>

int enqueue_tail(deque *deq, int key)
{
    return enqueue(deq, key);
}

int dequeue_head(deque *deq)
{
    return dequeue(deq);
}

int enqueue_head(deque *deq, int key)
{
    int full = queue_full(deq);
    if (full)
    {
        return 1;
    }
    else
    {
        deq->head = (deq->head + deq->size - 1) % deq->size;
        *(deq->keys + deq->head) = key;

        return 0;
    }
}

int dequeue_tail(deque *deq)
{
    int empty = queue_empty(deq);
    if (empty)
    {
        return 1;
    }
    else
    {
        deq->tail = (deq->tail + deq->size - 1) % deq->size;
        int x = *(deq->keys + deq->tail);

        return x;
    }
}
