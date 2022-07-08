#if !defined(WEIGHTED_ADJACENCY_LIST_H)
#define WEIGHTED_ADJACENCY_LIST_H

typedef struct wal_element // weighted graph's adjacency list element (vertex with edge weight)
{
    int index;                // index of vertex's adjacent vertex (undirected graph) or initial vertex's terminal vertex (directed graph)
    int weight;               // weight of edge formed by vertex and its adjacent vertex (undirected graph) or initial vertex and its terminal vertex (directed graph)
    struct wal_element *next; // pointer to next adjacent vertex (undirected graph) or terminal vertex (directed graph)
} wal_element;

typedef wal_element *wal;

/**
 * Initialize a weighted graph's adjacency list array
 * @return pointer to the head of the first weighted graph's adjacency list
 */
wal *wal_array_ctor(const int v);

/**
 * Destroy a weighted graph's adjacency list array
 * @param head double pointer to the head of the first adjacency list
 */
int wal_array_dtor(wal **head, const int v);

/**
 * Prepend vertex with edge weight to weighted graph's adjacency list
 * @param head pointer to the head of adjacency list
 * @param index index of vertex
 * @param weight weight of edge
 */
int wal_prepend(wal *head, const int index, const int weight);

#endif // WEIGHTED_ADJACENCY_LIST_H
