#include "stack.h"
#include <stdlib.h>

stack *stack_ctor(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->keys = (int *)malloc(sizeof(int) * size);

    s->top = -1;
    s->size = size;

    return s;
}

int stack_dtor(stack *s)
{
    free(s->keys);
    free(s);

    return 0;
}

bool stack_empty(const stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack_full(const stack *s)
{
    if (s->top == s->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int push(stack *s, int key)
{
    int full = stack_full(s);
    if (full)
    {
        return 1;
    }
    else
    {
        s->top += 1;
        *(s->keys + s->top) = key;

        return 0;
    }
}

int pop(stack *s)
{
    int empty = stack_empty(s);
    if (empty)
    {
        return -1;
    }
    else
    {
        s->top -= 1;
        return *(s->keys + s->top + 1);
    }
}
