#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initialize a doubly linked list element
 * @param key key value of element
 * @return pointer to doubly linked list element
 */
static dllist_element *element_ctor(int key);

dllist *dllist_ctor()
{
    dllist *head = (dllist *)malloc(sizeof(dllist));
    *head = NULL;

    return head;
}

int dllist_dtor(dllist **head)
{
    if (**head != NULL)
    {
        const dllist_element *p = (**head)->next;
        while (p != NULL)
        {
            free(**head);
            /* **head = NULL; */

            **head = (dllist_element *)p;
            p = (**head)->next;
        }
        free(**head);
        **head = NULL;

        free(*head);
        *head = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}

int dllist_length(dllist *head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        const dllist_element *p = *head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

dllist_element *dllist_search(dllist *head, int key)
{
    const dllist_element *p = *head;
    while (p != NULL)
    {
        if (p->key == key)
        {
            return (dllist_element *)p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

int dllist_prepend(dllist *head, int key)
{
    dllist_element *element = element_ctor(key);

    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        element->next = *head;
        (*head)->prev = element;
        *head = element;
    }

    return 0;
}

int dllist_append(dllist *head, int key)
{
    dllist_element *element = element_ctor(key);
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        dllist_element *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        element->prev = tail;
        tail->next = element;
    }

    return 0;
}

int dllist_insert(dllist *head, int index, int key)
{
    int length = dllist_length(head);
    if (index > -1 && index < length)
    {

        dllist_element *element = element_ctor(key);
        dllist_element *predecessor = *head;
        for (int i = 0; i < index; i++)
        {
            predecessor = predecessor->next;
        }

        dllist_element *successor = predecessor->next;

        predecessor->next = element;
        element->prev = predecessor;

        if (successor != NULL) // if the element at a specific index is not the tail of a doubly linked list
        {
            successor->prev = element;
            element->next = successor;
        }
        else
        {
            /* do nothing */
        }

        return 0;
    }
    else
    {
        if (*head == NULL)
        {
            dllist_prepend(head, key);

            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int dllist_delete(dllist *head, int index)
{
    int length = dllist_length(head);
    if (index > -1 && index < length && *head != NULL)
    {
        if (index == 0)
        {
            dllist_element *successor = (*head)->next;

            free(*head);
            *head = NULL;

            successor->prev = NULL;
            *head = successor;
        }
        else
        {
            dllist_element *element = *head;
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }

            dllist_element *predecessor = element->prev;
            dllist_element *successor = element->next;

            free(element);
            element = NULL;

            predecessor->next = successor;

            if (successor != NULL) // if the element at a specific index is not the tail of a doubly linked list
            {
                successor->prev = predecessor;
            }
            else
            {
                /* do nothing */
            }
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

int dllist_key(dllist *head, int index)
{
    int length = dllist_length(head);
    if (index > -1 && index < length)
    {
        const dllist_element *p = *head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return p->key;
    }
    else
    {
        return -1;
    }
}

static dllist_element *element_ctor(int key)
{
    dllist_element *element = (dllist_element *)malloc(sizeof(dllist_element));
    element->key = key;
    element->prev = NULL;
    element->next = NULL;

    return element;
}
