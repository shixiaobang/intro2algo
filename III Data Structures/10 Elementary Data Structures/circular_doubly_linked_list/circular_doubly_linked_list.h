#if !defined(CIRCULAR_DOUBLY_LINKED_LIST_H)
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include "doubly_linked_list.h"

typedef dll_element cdll_element;

typedef dll_element *cdll;

// Initialize a circular doubly linked list
cdll *cdll_ctor();

// Destroy a circular doubly linked list
int cdll_dtor(cdll *sentinel);

#endif // CIRCULAR_DOUBLY_LINKED_LIST_H
