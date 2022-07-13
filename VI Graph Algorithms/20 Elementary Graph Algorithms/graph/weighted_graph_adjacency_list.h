#if !defined(WEIGHTED_GRAPH_ADJACENCY_LIST_H)
#define WEIGHTED_GRAPH_ADJACENCY_LIST_H

#include "../adjacency_list/weighted_adjacency_list.h"

typedef struct
{
    walist *head; // adjacent list array of weighted graph
    int v;     // number of vertices
    int e;     // number of edges
} graph_walist;

/**
 * Create a weighted graph represented by an adjacency list
 * @param v number of vertices
 * @return pointer to weighted graph
 */
graph_walist *graph_walist_ctor(const int v);

/**
 * Destroy a weighted graph represented by an adjacency list
 * @param graph double pointer to weighted graph
 */
int graph_walist_dtor(graph_walist **graph);

/**
 * Add a weighted undirected edge to a weighted graph represented by an adjacency list
 * @param graph pointer to weighted graph
 * @param u index of edge's one endpoint
 * @param v index of edge's another endpoint
 */
int graph_walist_add_ue(graph_walist *graph, const int u, const int v, const int weight);

/**
 * Add a weighted directed edge to a weighted graph represented by an adjacency list
 * @param graph pointer to weighted graph
 * @param u index of directed edge's initial vertex
 * @param v index of directed edge's terminal vertex
 */
int graph_walist_add_de(graph_walist *graph, const int u, const int v, const int weight);

#endif // WEIGHTED_GRAPH_ADJACENCY_LIST_H
