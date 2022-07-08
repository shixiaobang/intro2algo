#include "weighted_adjacency_list.h"
#include <stdlib.h>

/**
 * Initialize a vertex with edge weight
 * @param index index of vertex
 * @param weight weight of edge
 * @return pointer to vertex with edge weight
 */
static wal_element *wal_element_ctor(const int index, const int weight);

/**
 * Destroy a weighted graph's adjacency list
 * @param head head of adjacency list
 */
static int wal_dtor(wal *head);

wal *wal_array_ctor(const int v)
{
    wal *head = (wal *)malloc(sizeof(wal_element *) * v);
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

int wal_array_dtor(wal **head, const int v)
{
    for (int i = 0; i < v; i++)
    {
        wal_dtor(*head + i);
    }
    free(*head);
    *head = NULL;

    return 0;
}

int wal_prepend(wal *head, const int index, const int weight)
{
    wal_element *element = wal_element_ctor(index, weight);
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

static wal_element *wal_element_ctor(const int index, const int weight)
{
    wal_element *element = (wal_element *)malloc(sizeof(wal_element));
    element->index = index;
    element->weight = weight;
    element->next = NULL;

    return element;
}

static int wal_dtor(wal *head)
{
    if (*head != NULL)
    {
        const wal_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (wal_element *)p;
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
