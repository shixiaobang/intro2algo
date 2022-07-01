#if !defined(SINGLY_LINKED_LIST_H)
#define SINGLY_LINKED_LIST_H

typedef struct singly_linked_list_element
{
    int key;
    struct singly_linked_list_element *next;
} sll_element;

typedef sll_element *sll;

sll *sll_ctor();

int sll_search(sll *head, int key);

int sll_prepend(sll *head, int key);

int sll_insert(sll *head, int index, int key);

int sll_delete(sll *head, int index);

#endif // SINGLY_LINKED_LIST_H
