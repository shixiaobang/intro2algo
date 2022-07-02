#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

typedef struct singly_linked_list_element
{
    int key;
    struct singly_linked_list_element *next;
} sll_element;

typedef sll_element *sll;

// Initialize a singly linked list
sll *sll_ctor();

// Destroy a singly linked list
int sll_dtor(sll *head);

// Return the length of a singly linked list
int sll_length(sll *head);

// Return index of an element with key value in singly linked list
int sll_search(sll *head, int key);

int sll_prepend(sll *head, int key);

int sll_append(sll *head, int key);

// Insert a new element after an element at a specific index in a singly linked list
int sll_insert(sll *head, int index, int key);

// Delete element of specific index in singly linked list
int sll_delete(sll *head, int index);

// Return key value from specific index of singly linked list
int sll_key(sll *head, int index);

#endif // SINGLY_LINKED_LIST_H
