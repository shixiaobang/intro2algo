#include "doubly_linked_list.h"
#include <stdlib.h>

dll_element *element_ctor(int key)
{
    dll_element *element = (dll_element *)malloc(sizeof(dll_element));
    element->key = key;
    element->prev = NULL;
    element->next = NULL;

    return element;
}

dll *dll_ctor()
{
    dll *head = (dll *)malloc(sizeof(dll));
    *head = NULL;

    return head;
}

int dll_dtor(dll *head)
{
    if (*head != NULL)
    {
        const dll_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (dll_element *)p;
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

int dll_length(dll *head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        const dll_element *p = *head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

int dll_search(dll *head, int key)
{
    const dll_element *p = *head;
    int index = -1;
    while (p != NULL)
    {
        if (p->key == key)
        {
            return index;
        }
        else
        {
            p = p->next;
            index++;
        }
    }

    return -1;
}

int dll_prepend(dll *head, int key)
{
    dll_element *element = element_ctor(key);

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

int dll_append(dll *head, int key)
{
    dll_element *element = element_ctor(key);
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        dll_element *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        element->prev = tail;
        tail->next = element;
    }

    return 0;
}

int dll_insert(dll *head, int index, int key)
{
    int length = dll_length(head);
    if (index > -1 && index < length)
    {
        if (*head == NULL)
        {
            dll_prepend(head, key);
        }
        else
        {
            dll_element *element = element_ctor(key);
            dll_element *predecessor = *head;
            for (int i = 0; i < index; i++)
            {
                predecessor = predecessor->next;
            }

            dll_element *successor = predecessor->next;

            predecessor->next = element;
            element->prev = predecessor;

            // If the element at a specific index is not the tail of a doubly linked list
            if (successor != NULL)
            {
                successor->prev = element;
                element->next = successor;
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

int dll_delete(dll *head, int index)
{
    int length = dll_length(head);
    if (index > -1 && index < length && *head != NULL)
    {
        if (index == 0)
        {
            dll_element *successor = (*head)->next;

            free(*head);
            *head = NULL;

            successor->prev = NULL;
            *head = successor;
        }
        else
        {
            dll_element *element = *head;
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }

            dll_element *predecessor = element->prev;
            dll_element *successor = element->next;

            free(element);
            element = NULL;

            predecessor->next = successor;

            // If the element at a specific index is not the tail of a doubly linked list
            if (successor != NULL)
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

int dll_key(dll *head, int index)
{
    int length = dll_length(head);
    if (index > -1 && index < length)
    {
        const dll_element *p = *head;
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
