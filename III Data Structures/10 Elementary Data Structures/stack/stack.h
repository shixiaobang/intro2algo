#if !defined(STACK_H)
#define STACK_H

#include <stdbool.h>

typedef struct
{
    int *p_key;
    int top;
    int size;
} stack;

// Initialize a stack of at most n elements
stack *stack_ctor(int size);

// Destroy a stack
int stack_dtor(stack *s);

// Test whether the queue is empty
bool stack_empty(const stack *s);

// Test whether the queue is full
bool stack_full(const stack *s);

// INSERT operation on a stack
int push(stack *s, int key);

// DELETE operation on a stack, returned the one most recently pushed key value
int pop(stack *s);

#endif // STACK_H
