#if !defined(ADJACENCY_LIST_H)
#define ADJACENCY_LIST_H

typedef struct al_element // adjacency list element (vertex)
{
    int index;               // index of vertex's adjacent vertex (undirected graph) or initial vertex's terminal vertex (directed graph)
    struct al_element *next; // pointer to next adjacent vertex (undirected graph) or terminal vertex (directed graph)
} al_element;

typedef al_element *al;

/**
 * Initialize an adjacency list array
 * @return pointer to the head of the first adjacency list
 */
al *al_array_ctor(const int v);

/**
 * Destroy an adjacency list array
 * @param head double pointer to the head of the first adjacency list
 */
int al_array_dtor(al **head, const int v);

/**
 * Prepend vertex to adjacency list
 * @param head pointer to the head of adjacency list
 * @param index index of vertex
 */
int al_prepend(al *head, const int index);

#endif // ADJACENCY_LIST_H
