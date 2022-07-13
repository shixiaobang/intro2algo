#include "weighted_adjacency_list.h"
#include <stdlib.h>

/**
 * Initialize a vertex with edge weight
 * @param index index of vertex
 * @param weight weight of edge
 * @return pointer to vertex with edge weight
 */
static walist_element *walist_element_ctor(const int index, const int weight);

/**
 * Destroy a weighted graph's adjacency list
 * @param head head of adjacency list
 */
static int walist_dtor(walist *head);

walist *walist_array_ctor(const int v)
{
    walist *head = (walist *)malloc(sizeof(walist_element *) * v);
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

int walist_array_dtor(walist **head, const int v)
{
    for (int i = 0; i < v; i++)
    {
        walist_dtor(*head + i);
    }
    free(*head);
    *head = NULL;

    return 0;
}

int walist_prepend(walist *head, const int index, const int weight)
{
    walist_element *element = walist_element_ctor(index, weight);
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

static walist_element *walist_element_ctor(const int index, const int weight)
{
    walist_element *element = (walist_element *)malloc(sizeof(walist_element));
    element->index = index;
    element->weight = weight;
    element->next = NULL;

    return element;
}

static int walist_dtor(walist *head)
{
    if (*head != NULL)
    {
        const walist_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (walist_element *)p;
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
