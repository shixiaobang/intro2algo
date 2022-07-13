#if !defined(ADJACENCY_LIST_H)
#define ADJACENCY_LIST_H

typedef struct alist_element // adjacency list element (vertex)
{
    int index;                  // index of vertex's adjacent vertex (undirected graph) or initial vertex's terminal vertex (directed graph)
    struct alist_element *next; // pointer to next adjacent vertex (undirected graph) or terminal vertex (directed graph)
} alist_element;

typedef alist_element *alist;

/**
 * Initialize an adjacency list array
 * @return pointer to the head of the first adjacency list
 */
alist *alist_array_ctor(const int v);

/**
 * Destroy an adjacency list array
 * @param head double pointer to the head of the first adjacency list
 */
int alist_array_dtor(alist **head, const int v);

/**
 * Prepend vertex to adjacency list
 * @param head pointer to the head of adjacency list
 * @param index index of vertex
 */
int alist_prepend(alist *head, const int index);

#endif // ADJACENCY_LIST_H
