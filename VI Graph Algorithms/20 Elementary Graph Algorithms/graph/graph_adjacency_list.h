#if !defined(GRAPH_ADJACENCY_LIST_H)
#define GRAPH_ADJACENCY_LIST_H

#include "../adjacency_list/adjacency_list.h"

typedef struct
{
    alist *head; // adjacent list array of graph
    int v;       // number of vertices
    int e;       // number of edges
} graph_alist;

/**
 * Create a graph represented by an adjacency list
 * @param v number of vertices
 * @return pointer to graph
 */
graph_alist *graph_alist_ctor(const int v);

/**
 * Destroy a graph represented by an adjacency list
 * @param graph double pointer to graph
 */
int graph_alist_dtor(graph_alist **graph);

/**
 * Add an undirected edge to a graph represented by an adjacency list
 * @param graph pointer to graph
 * @param u index of edge's one endpoint
 * @param v index of edge's another endpoint
 */
int graph_alist_add_ue(graph_alist *graph, const int u, const int v);

/**
 * Add a directed edge to a graph represented by an adjacency list
 * @param graph pointer to graph
 * @param u index of directed edge's initial vertex
 * @param v index of directed edge's terminal vertex
 */
int graph_alist_add_de(graph_alist *graph, const int u, const int v);

#endif // GRAPH_ADJACENCY_LIST_H
