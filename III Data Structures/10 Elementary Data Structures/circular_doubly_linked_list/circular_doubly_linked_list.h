#if !defined(CIRCULAR_DOUBLY_LINKED_LIST_H)
#define CIRCULAR_DOUBLY_LINKED_LIST_H

typedef struct circular_doubly_linked_list_element
{
    int key;
    struct circular_doubly_linked_list_element *prev;
    struct circular_doubly_linked_list_element *next;
} cdllist_element;

typedef cdllist_element *cdllist;

/**
 * Initialize a circular doubly linked list
 * @return pointer to the sentinel of circular doubly linked list
 */
cdllist *cdllist_ctor();

/**
 * Destroy a circular doubly linked list
 * @param sentinel double pointer to the sentinel of circular doubly linked list
 */
int cdllist_dtor(cdllist **sentinel);

/**
 * Return the length of circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @return length of circular doubly linked list
 */
int cdllist_length(cdllist *sentinel);

/**
 * Return the index of an element with a specific key value in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 * @return index of element with specific key value
 */
cdllist_element *cdllist_search(cdllist *sentinel, int key);

/**
 * Insert a new element at the head of a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 */
int cdllist_prepend(cdllist *sentinel, int key);

/**
 * Insert a new element at the tail of a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param key key value
 */
int cdllist_append(cdllist *sentinel, int key);

/**
 * Insert a new element after an element at a specific index in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 * @param key key value
 */
int cdllist_insert(cdllist *sentinel, int index, int key);

/**
 * Delete an element at a specific index in a circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 */
int cdllist_delete(cdllist *sentinel, int index);

/**
 * Return key value from specific index of circular doubly linked list
 * @param sentinel pointer to the sentinel of circular doubly linked list
 * @param index index of element
 */
int cdllist_key(cdllist *sentinel, int index);

#endif // CIRCULAR_DOUBLY_LINKED_LIST_H
