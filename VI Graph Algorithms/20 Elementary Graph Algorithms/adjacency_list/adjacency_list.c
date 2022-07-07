#include "adjacency_list.h"
#include <stdlib.h>

/**
 * Initialize a vertex
 * @param index index of vertex
 * @return pointer to vertex
 */
static al_element *al_element_ctor(const int index);

/**
 * Destroy a adjacency list
 * @param head
 */
static int al_dtor(al *head);

al *al_array_ctor(const int v)
{
    al *head = (al *)malloc(sizeof(al_element *) * v);
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

int al_array_dtor(al **head, const int v)
{
    for (int i = 0; i < v; i++)
    {
        al_dtor(*head + i);
    }
    free(*head);
    *head = NULL;

    return 0;
}

int al_prepend(al *head, const int index)
{
    al_element *element = al_element_ctor(index);
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

static al_element *al_element_ctor(const int index)
{
    al_element *element = (al_element *)malloc(sizeof(al_element));
    element->index = index;
    element->next = NULL;

    return element;
}

static int al_dtor(al *head)
{
    if (*head != NULL)
    {
        const al_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (al_element *)p;
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
