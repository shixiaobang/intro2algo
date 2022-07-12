#include "singly_linked_list.h"
#include <stdlib.h>

/**
 * Initialize a singly linked list element
 * @param key key value of element
 * @return pointer to singly linked list element
 */ 
static sllist_element *element_ctor(int key);

sllist *sllist_ctor()
{
    sllist *head = (sllist *)malloc(sizeof(sllist));
    *head = NULL;

    return head;
}

int sllist_dtor(sllist **head)
{
    if (**head != NULL)
    {
        const sllist_element *p = (**head)->next;
        while (p != NULL)
        {
            free(**head);
            **head = NULL;

            **head = (sllist_element *)p;
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

int sllist_length(sllist *head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        const sllist_element *p = *head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

sllist_element *sllist_search(sllist *head, int key)
{
    const sllist_element *p = *head;
    while (p != NULL)
    {
        if (p->key == key)
        {
            return (sllist_element *)p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

int sllist_prepend(sllist *head, int key)
{
    sllist_element *element = element_ctor(key);
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        element->next = *head;
        *head = element;
    }

    return 0;
}

int sllist_append(sllist *head, int key)
{
    sllist_element *element = element_ctor(key);
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        sllist_element *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = element;
    }

    return 0;
}

int sllist_insert(sllist *head, int index, int key)
{
    int length = sllist_length(head);
    if (index > -1 && index < length)
    {
        if (*head == NULL)
        {
            sllist_prepend(head, key);
        }
        else
        {
            sllist_element *element = element_ctor(key);
            sllist_element *predecessor = *head;
            for (int i = 0; i < index; i++)
            {
                predecessor = predecessor->next;
            }

            sllist_element *successor = predecessor->next;
            predecessor->next = element;

            element->next = successor;
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

int sllist_delete(sllist *head, int index)
{
    int length = sllist_length(head);
    if (index > -1 && index < length && *head != NULL)
    {
        if (index == 0)
        {
            sllist_element *successor = (*head)->next;

            free(*head);
            *head = NULL;

            *head = successor;
        }
        else
        {
            sllist_element *predecessor = *head;
            for (int i = 0; i < index - 1; i++)
            {
                predecessor = predecessor->next;
            }

            sllist_element *element = predecessor->next;
            sllist_element *successor = element->next;

            free(element);
            element = NULL;

            predecessor->next = successor;
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

int sllist_key(sllist *head, int index)
{
    int length = sllist_length(head);
    if (index > -1 && index < length)
    {
        const sllist_element *p = *head;
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

static sllist_element *element_ctor(int key)
{
    sllist_element *element = (sllist_element *)malloc(sizeof(sllist_element));
    element->key = key;
    element->next = NULL;

    return element;
}
