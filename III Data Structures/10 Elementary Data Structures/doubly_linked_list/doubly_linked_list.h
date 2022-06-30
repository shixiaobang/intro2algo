#if !defined(DOUBLY_LINKED_LIST_H)
#define DOUBLY_LINKED_LIST_H

typedef struct doubly_linked_list
{
    int key;
    struct doubly_linked_list *prev;
    struct doubly_linked_list *next;
} dll;

dll *doubly_linked_list_ctor();

int doubly_linked_list_dtor(dll *list);

#endif // DOUBLY_LINKED_LIST_H
