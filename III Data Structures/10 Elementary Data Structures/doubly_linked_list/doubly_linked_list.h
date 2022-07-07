#if !defined(DOUBLY_LINKED_LIST_H)
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_list_element
{
    int key;
    struct doubly_linked_list_element *prev;
    struct doubly_linked_list_element *next;
} dll_element;

typedef dll_element *dll;

// Initialize a doubly linked list
dll *dll_ctor();

// Destroy a doubly linked list
int dll_dtor(dll **head);

// Return the length of a doubly linked list
int dll_length(dll *head);

// Return the index of an element with a specific key value in a doubly linked list
dll_element *dll_search(dll *head, int key);

// Insert a new element at the head of a doubly linked list
int dll_prepend(dll *head, int key);

// Insert a new element at the tail of a doubly linked list
int dll_append(dll *head, int key);

// Insert a new element after an element at a specific index in a doubly linked list
int dll_insert(dll *head, int index, int key);

// Delete an element at a specific index in a doubly linked list
int dll_delete(dll *head, int index);

// Return key value from specific index of doubly linked list
int dll_key(dll *head, int index);

#endif // DOUBLY_LINKED_LIST_H
