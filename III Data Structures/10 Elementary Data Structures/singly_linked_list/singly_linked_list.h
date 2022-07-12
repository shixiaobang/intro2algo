#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

typedef struct singly_linked_list_element
{
    int key;
    struct singly_linked_list_element *next;
} sllist_element;

typedef sllist_element *sllist;

// Initialize a singly linked list
sllist *sllist_ctor();

// Destroy a singly linked list
int sllist_dtor(sllist **head);

// Return the length of a singly linked list
int sllist_length(sllist *head);

// Return an element with a specific key value in a singly linked list
sllist_element *sllist_search(sllist *head, int key);

// Insert a new element at the head of a singly linked list
int sllist_prepend(sllist *head, int key);

// Insert a new element at the tail of a singly linked list
int sllist_append(sllist *head, int key);

// Insert a new element after an element at a specific index in a singly linked list
int sllist_insert(sllist *head, int index, int key);

// Delete an element at a specific index in a singly linked list
int sllist_delete(sllist *head, int index);

// Return key value from specific index of singly linked list
int sllist_key(sllist *head, int index);

#endif // SINGLY_LINKED_LIST_H
