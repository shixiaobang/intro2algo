#include "circular_doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initialize a circular doubly linked list element
 * @param key key value of element
 * @return pointer to circular doubly linked list element
 */
static cdllist_element *element_ctor(int key);

cdllist *cdllist_ctor()
{
    cdllist *sentinel = (cdllist *)malloc(sizeof(cdllist));
    cdllist_element *nil = (cdllist_element *)malloc(sizeof(cdllist_element)); // initialize a sentinel element of circular doubly linked list
    nil->prev = nil;
    nil->next = nil;
    *sentinel = nil;

    return sentinel;
}

int cdllist_dtor(cdllist **sentinel)
{
    if (**sentinel != NULL)
    {
        const cdllist_element *p = (**sentinel)->next; // p is the head of circular doubly linked list
        const cdllist_element *nil = **sentinel;       // pointer to the sentinel element of circular doubly linked list
        while (p != nil)
        {
            free(**sentinel);
            // **sentinel = NULL;

            **sentinel = (cdllist_element *)p;
            p = (**sentinel)->next;
        }
        free(**sentinel);
        **sentinel = NULL;

        free(*sentinel);
        *sentinel = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}

int cdllist_length(cdllist *sentinel)
{
    if ((*sentinel)->next == *sentinel)
    {
        return 0;
    }
    else
    {
        const cdllist_element *p = (*sentinel)->next;
        int length = 0;
        while (p != *sentinel)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

cdllist_element *cdllist_search(cdllist *sentinel, int key)
{
    const cdllist_element *p = (*sentinel)->next;
    while (p != *sentinel)
    {
        if (p->key == key)
        {
            return (cdllist_element *)p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

int cdllist_prepend(cdllist *sentinel, int key)
{
    if (*sentinel != NULL)
    {
        cdllist_element *element = element_ctor(key);

        element->next = (*sentinel)->next;
        (*sentinel)->next->prev = element;
        (*sentinel)->next = element;
        element->prev = *(sentinel);

        return 0;
    }
    else
    {
        return 1;
    }
}

int cdllist_append(cdllist *sentinel, int key)
{
    if (*sentinel != NULL)
    {
        cdllist_element *element = element_ctor(key);
        cdllist_element *tail = *sentinel;
        while (tail->next != *sentinel)
        {
            tail = tail->next;
        }
        (*sentinel)->prev = element;
        element->next = *sentinel;
        tail->next = element;
        element->prev = tail;
    }
    else
    {
        return 1;
    }
}

int cdllist_insert(cdllist *sentinel, int index, int key)
{
    int length = cdllist_length(sentinel);
    if (index > -1 && index < length)
    {
        cdllist_element *element = element_ctor(key);
        cdllist_element *predecessor = (*sentinel)->next;
        for (int i = 0; i < index; i++)
        {
            predecessor = predecessor->next;
        }

        cdllist_element *successor = predecessor->next;

        predecessor->next = element;
        element->prev = predecessor;

        successor->prev = element;
        element->next = successor;

        return 0;
    }
    else
    {
        return 1;
    }
}

int cdllist_delete(cdllist *sentinel, int index)
{
    int length = cdllist_length(sentinel);
    if (index > -1 && index < length && *sentinel != NULL)
    {
        if ((*sentinel)->next != *sentinel)
        {
            cdllist_element *element = (*sentinel)->next;
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }
            cdllist_element *predecessor = element->prev;
            cdllist_element *successor = element->next;

            free(element);
            element = NULL;

            predecessor->next = successor;
            successor->prev = predecessor;

            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int cdllist_key(cdllist *sentinel, int index)
{
    int length = cdllist_length(sentinel);
    if (index > -1 && index < length)
    {
        const cdllist_element *p = (*sentinel)->next;
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

static cdllist_element *element_ctor(int key)
{
    cdllist_element *element = (cdllist_element *)malloc(sizeof(cdllist_element));
    element->key = key;
    element->prev = NULL;
    element->next = NULL;

    return element;
}
