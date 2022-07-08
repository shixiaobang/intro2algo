#if !defined(CIRCULAR_DOUBLY_LINKED_LIST_H)
#define CIRCULAR_DOUBLY_LINKED_LIST_H

typedef struct circular_doubly_linked_list_element
{
    int key;
    struct circular_doubly_linked_list_element *prev;
    struct circular_doubly_linked_list_element *next;
} cdll_element;

typedef cdll_element *cdll;

/**
 * Initialize a circular doubly linked list
 * @return pointer to the sentinel of circular doubly linked list
 */
cdll *cdll_ctor();

/**
 * Destroy a circular doubly linked list
 * @param sentinel double pointer to the sentinel of circular doubly linked list
 */
int cdll_dtor(cdll **sentinel);

/**
 * Return the length of circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @return length of circular doubly linked list
 */
int cdll_length(cdll *sentinel);

/**
 * Return the index of an element with a specific key value in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 * @return index of element with specific key value
 */
cdll_element *cdll_search(cdll *sentinel, int key);

/**
 * Insert a new element at the head of a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 */
int cdll_prepend(cdll *sentinel, int key);

/**
 * Insert a new element at the tail of a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 */
int cdll_append(cdll *sentinel, int key);

/**
 * Insert a new element after an element at a specific index in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 * @param key key value
 */
int cdll_insert(cdll *sentinel, int index, int key);

/**
 * Delete an element at a specific index in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 */
int cdll_delete(cdll *sentinel, int index);

/**
 * Return key value from specific index of circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 */
int cdll_key(cdll *sentinel, int index);

#endif // CIRCULAR_DOUBLY_LINKED_LIST_H
