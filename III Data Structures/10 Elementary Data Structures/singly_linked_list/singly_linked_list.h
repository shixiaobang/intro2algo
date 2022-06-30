#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

typedef struct singly_linked_list
{
    int key;
    struct singly_linked_list *next;
} sll;

sll *singly_linked_list_ctor();

int singly_linked_list_dtor(sll *list);

#endif // SINGLY_LINKED_LIST_H
