#if !defined(CIRCULAR_SINGLY_LINKED_LIST)
#define CIRCULAR_SINGLY_LINKED_LIST

typedef struct circular_singly_linked_list_element
{
    int key;
    struct circular_singly_linked_list_element *next;
} csllist_element;

typedef csllist_element *csllist;

/**
 * Initialize a circular singly linked list
 * @return pointer to the head of circular singly linked list
 */
csllist *csllist_ctor();

/**
 * Destroy a circular singly linked list
 * @param head double pointer to the head of circular singly linked list
 */
int csllist_dtor(csllist **head);

/**
 * Return the length of a circular singly linked list
 * @return length of a circular singly linked list
 */
int csllist_length(csllist *head);

/**
 * Return an element with a specific key value in a circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param key a specific key value
 * @return pointer to an element
 */
csllist_element *csllist_search(csllist *head, int key);

/**
 * Insert a new element at the head of a circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param key key value of new element
 */
int csllist_prepend(csllist *head, int key);

/**
 * Insert a new element at the tail of a circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param key key value of new element
 */
int csllist_append(csllist *head, int key);

/**
 * Insert a new element after an element at a specific index in a circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param index a specific index
 * @param key key value of new element
 */
int csllist_insert(csllist *head, int index, int key);

/**
 * Delete an element at a specific index in a circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param index a specific index
 */
int csllist_delete(csllist *head, int index);

/**
 * Return key value from specific index of circular singly linked list
 * @param head pointer to the head of circular singly linked list
 * @param index a specific index
 */
int csllist_key(csllist *head, int index);

#endif // CIRCULAR_SINGLY_LINKED_LIST
