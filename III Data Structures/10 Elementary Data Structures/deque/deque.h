#if !defined(DEQUE_H)
#define DEQUE_H

#include "../queue/queue.h"

typedef queue deque;

// INSERT operation on a deque at tail
int enqueue_tail(deque *deq, int key);

// DELETE operation on a deque at head, return the key value formerly at the head of the deque
int dequeue_head(deque *deq);

// INSERT operation on a deque at head
int enqueue_head(deque *deq, int key);

// DELETE operation on a deque at tail, return the key value formerly at the head of the deque
int dequeue_tail(deque *deq);

#endif // DEQUE_H
