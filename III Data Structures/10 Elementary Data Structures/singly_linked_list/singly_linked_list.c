#include "singly_linked_list.h"
#include <stdlib.h>

sll_element *element_ctor(int key)
{
    sll_element *element = (sll_element *)malloc(sizeof(sll_element));
    element->key = key;
    element->next = NULL;

    return element;
}

sll *sll_ctor()
{
    sll *head = (sll *)malloc(sizeof(sll));
    *head = NULL;

    return head;
}

int sll_dtor(sll *head)
{
    if (*head != NULL)
    {
        const sll_element *p = (*head)->next;
        while (p != NULL)
        {
            free(*head);
            *head = NULL;

            *head = (sll_element *)p;
            p = (*head)->next;
        }
        free(*head);
        *head = NULL;

        free(head);
        /* head = NULL */
        // set pointer to null is invalid here, please remember to do this in the main function

        return 0;
    }
    else
    {
        return 1;
    }
}

int sll_length(sll *head)
{
    if (*head == NULL)
    {
        return 0;
    }
    else
    {
        const sll_element *p = *head;
        int length = 0;
        while (p != NULL)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

sll_element *sll_search(sll *head, int key)
{
    const sll_element *p = *head;

    int index = -1;
    while (p != NULL)
    {
        if (p->key == key)
        {
            return (sll_element *)p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

int sll_prepend(sll *head, int key)
{
    sll_element *element = element_ctor(key);

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

int sll_append(sll *head, int key)
{
    sll_element *element = element_ctor(key);
    if (*head == NULL)
    {
        *head = element;
    }
    else
    {
        sll_element *tail = *head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = element;
    }

    return 0;
}

int sll_insert(sll *head, int index, int key)
{
    int length = sll_length(head);
    if (index > -1 && index < length)
    {
        if (*head == NULL)
        {
            sll_prepend(head, key);
        }
        else
        {
            sll_element *element = element_ctor(key);
            sll_element *predecessor = *head;
            for (int i = 0; i < index; i++)
            {
                predecessor = predecessor->next;
            }

            sll_element *successor = predecessor->next;
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

int sll_delete(sll *head, int index)
{
    int length = sll_length(head);
    if (index > -1 && index < length && *head != NULL)
    {
        if (index == 0)
        {
            sll_element *successor = (*head)->next;

            free(*head);
            *head = NULL;

            *head = successor;
        }
        else
        {
            sll_element *predecessor = *head;
            for (int i = 0; i < index - 1; i++)
            {
                predecessor = predecessor->next;
            }

            sll_element *element = predecessor->next;
            sll_element *successor = element->next;

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

int sll_key(sll *head, int index)
{
    int length = sll_length(head);
    if (index > -1 && index < length)
    {
        const sll_element *p = *head;
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
