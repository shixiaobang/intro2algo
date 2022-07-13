#include "adjacency_list.h"
#include <stdlib.h>

/**
 * Initialize a vertex
 * @param index index of vertex
 * @return pointer to vertex
 */
static alist_element *alist_element_ctor(const int index);

/**
 * Destroy a adjacency list
 * @param head
 */
static int alist_dtor(alist *head);

alist *alist_array_ctor(const int v)
{
    alist *head = (alist *)malloc(sizeof(alist_element *) * v);
    if (head != NULL)
    {
        for (int i = 0; i < v; i++)
        {
            *(head + i) = NULL;
        }
    }
    else
    {
        /* do nothing */
    }

    return head;
}

int alist_array_dtor(alist **head, const int v)
{
    for (int i = 0; i < v; i++)
    {
        alist_dtor(*head + i);
    }
    free(*head);
    *head = NULL;

    return 0;
}

int alist_prepend(alist *head, const int index)
{
    alist_element *element = alist_element_ctor(index);
    if (*head != NULL)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        *head = element;
    }

    return 0;
}

static alist_element *alist_element_ctor(const int index)
{
    alist_element *element = (alist_element *)malloc(sizeof(alist_element));
    element->index = index;
    element->next = NULL;

    return element;
}

static int alist_dtor(alist *head)
{
    if (*head != NULL)
    {
        const alist_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (alist_element *)p;
            p = (*head)->next;
        }
        free(*head);
        *head = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
