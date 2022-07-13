#if !defined(WEIGHTED_ADJACENCY_LIST_H)
#define WEIGHTED_ADJACENCY_LIST_H

typedef struct walist_element // weighted graph's adjacency list element (vertex with edge weight)
{
    int index;                   // index of vertex's adjacent vertex (undirected graph) or initial vertex's terminal vertex (directed graph)
    int weight;                  // weight of edge formed by vertex and its adjacent vertex (undirected graph) or initial vertex and its terminal vertex (directed graph)
    struct walist_element *next; // pointer to next adjacent vertex (undirected graph) or terminal vertex (directed graph)
} walist_element;

typedef walist_element *walist;

/**
 * Initialize a weighted graph's adjacency list array
 * @return pointer to the head of the first weighted graph's adjacency list
 */
walist *walist_array_ctor(const int v);

/**
 * Destroy a weighted graph's adjacency list array
 * @param head double pointer to the head of the first adjacency list
 */
int walist_array_dtor(walist **head, const int v);

/**
 * Prepend vertex with edge weight to weighted graph's adjacency list
 * @param head pointer to the head of adjacency list
 * @param index index of vertex
 * @param weight weight of edge
 */
int walist_prepend(walist *head, const int index, const int weight);

#endif // WEIGHTED_ADJACENCY_LIST_H
