#if !defined(DOUBLY_LINKED_LIST_H)
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_list_element
{
    int key;
    struct doubly_linked_list_element *prev;
    struct doubly_linked_list_element *next;
} dllist_element;

typedef dllist_element *dllist;

/**
 * Initialize a doubly linked list
 * @return pointer to the head of doubly linked list
 */
dllist *dllist_ctor();

/**
 * Destroy a doubly linked list
 * @param head double pointer to the head of doubly linked list
 */
int dllist_dtor(dllist **head);

/**
 * Return the length of a doubly linked list
 * @param head pointer to the head of doubly linked list
 */
int dllist_length(dllist *head);

/**
 * Return an element with a specific key value in a doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param key a specific key value
 * @return pointer to an element
 */
dllist_element *dllist_search(dllist *head, int key);

/**
 * Insert a new element at the head of a doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param key key value of new element
 */
int dllist_prepend(dllist *head, int key);

/**
 * Insert a new element at the tail of a doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param key key value of new element
 */
int dllist_append(dllist *head, int key);

/**
 * Insert a new element after an element at a specific index in a doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param index a specific index
 * @param key key value of new element
 */
int dllist_insert(dllist *head, int index, int key);


/**
 * Delete an element at a specific index in a doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param index a specific index
 */
int dllist_delete(dllist *head, int index);


/**
 * RReturn key value from specific index of doubly linked list
 * @param head pointer to the head of doubly linked list
 * @param index a specific index
 */
int dllist_key(dllist *head, int index);

#endif // DOUBLY_LINKED_LIST_H
