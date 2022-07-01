#include "singly_linked_list.h"
#include <stdlib.h>

sll *sll_ctor()
{
    sll *head = (sll *)malloc(sizeof(sll));
    *head = NULL;

    return head;
}

int sll_search(sll *head, int key)
{
    sll_element *p = *head;
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

int sll_prepend(sll *head, int key)
{
    sll_element *element = (sll_element *)malloc(sizeof(sll_element));
    element->key = key;

    if (*head == NULL)
    {
        *head = element;
        element->next = NULL;

        return 0;
    }
    else
    {
        if ((*head)->next == NULL)
        {
            (*head)->next = element;
            element->next = NULL;

            return 0;
        }
        else
        {
            sll_element *head_next = (*head)->next;
            (*head)->next = element;
            element->next = head_next;

            return 0;
        }

        return 1;
    }
}

int sll_insert(sll *head, int index, int key)
{
    if (*head == NULL)
    {
        return 1;
    }
    else
    {
        sll_element *element = (sll_element *)malloc(sizeof(sll_element));
        element->key = key;

        sll_element *p = *head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }

        sll_element *temp = p->next;
        p->next = element;
        element->next = temp;

        return 0;
    }
}

int sll_delete(sll *head, int index)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        sll_element *p = *head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        sll_element *temp = p->next;
        p->next = (p->next)->next;

        free(temp);

        return 0;
    }
}
