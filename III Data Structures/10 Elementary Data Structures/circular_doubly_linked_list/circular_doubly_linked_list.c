#include "circular_doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initialize a circular doubly linked list element
 * @param key key value of element
 * @return pointer to circular doubly linked list element
 */
static cdll_element *element_ctor(int key);

cdll *cdll_ctor()
{
    cdll *sentinel = (cdll *)malloc(sizeof(cdll));
    cdll_element *nil = (cdll_element *)malloc(sizeof(cdll_element)); // initialize a sentinel element of circular doubly linked list
    nil->prev = nil;
    nil->next = nil;
    *sentinel = nil;

    return sentinel;
}

int cdll_dtor(cdll **sentinel)
{
    if (**sentinel != NULL)
    {
        const cdll_element *p = (**sentinel)->next; // p is the head of circular doubly linked list
        const cdll_element *nil = **sentinel;       // pointer to the sentinel element of circular doubly linked list
        while (p != nil)
        {
            free(**sentinel);
            // **sentinel = NULL;

            **sentinel = (cdll_element *)p;
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

int cdll_length(cdll *sentinel)
{
    if ((*sentinel)->next == *sentinel)
    {
        return 0;
    }
    else
    {
        const cdll_element *p = (*sentinel)->next;
        int length = 0;
        while (p != *sentinel)
        {
            p = p->next;
            length++;
        }

        return length;
    }
}

cdll_element *cdll_search(cdll *sentinel, int key)
{
    const cdll_element *p = (*sentinel)->next;
    while (p != *sentinel)
    {
        if (p->key == key)
        {
            return (cdll_element *)p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

int cdll_prepend(cdll *sentinel, int key)
{
    if (*sentinel != NULL)
    {
        cdll_element *element = element_ctor(key);

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

int cdll_append(cdll *sentinel, int key)
{
    if (*sentinel != NULL)
    {
        cdll_element *element = element_ctor(key);
        cdll_element *tail = *sentinel;
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

int cdll_insert(cdll *sentinel, int index, int key)
{
    int length = cdll_length(sentinel);
    if (index > -1 && index < length)
    {
        cdll_element *element = element_ctor(key);
        cdll_element *predecessor = (*sentinel)->next;
        for (int i = 0; i < index; i++)
        {
            predecessor = predecessor->next;
        }

        cdll_element *successor = predecessor->next;

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

int cdll_delete(cdll *sentinel, int index)
{
    int length = cdll_length(sentinel);
    if (index > -1 && index < length && *sentinel != NULL)
    {
        if ((*sentinel)->next != *sentinel)
        {
            cdll_element *element = (*sentinel)->next;
            for (int i = 0; i < index; i++)
            {
                element = element->next;
            }
            cdll_element *predecessor = element->prev;
            cdll_element *successor = element->next;

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

int cdll_key(cdll *sentinel, int index)
{
    int length = cdll_length(sentinel);
    if (index > -1 && index < length)
    {
        const cdll_element *p = (*sentinel)->next;
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

static cdll_element *element_ctor(int key)
{
    cdll_element *element = (cdll_element *)malloc(sizeof(cdll_element));
    element->key = key;
    element->prev = NULL;
    element->next = NULL;

    return element;
}
