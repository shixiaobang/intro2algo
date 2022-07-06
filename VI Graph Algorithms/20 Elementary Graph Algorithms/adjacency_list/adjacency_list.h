#if !defined(ADJACENCY_LIST_H)
#define ADJACENCY_LIST_H

#include "../edge/edge.h"

typedef struct vertex // vertex
{
    int index;           // index of vertex's adjacent vertex (undirected graph) or initial vertex's terminal vertex (directed graph)
    struct vertex *next; // pointer to next adjacent vertex (undirected graph) or terminal vertex (directed graph)
} vertex;

typedef struct vertex_edge_weight // vertex with edge weight
{
    int index;
    int weight; // weight of an edge formed by a vertex and its adjacent vertex (undirected graph) or initial vertex and its terminal vertex (directed graph)
    struct vertex_edge_weight *next;
} vertex_edge_weight;

typedef vertex **adj_list;

typedef vertex_edge_weight **weighted_adj_list;

typedef struct
{
    adj_list list; // adjacent list of graph
    int v;         // number of vertices
    int e;         // number of edges
} graph_adj_list;

typedef struct
{
    weighted_adj_list list; // adjacent list of weighted graph
    int v;                  // number of vertices
    int e;                  // number of edges
} weighted_graph_adj_list;

/**
 * Create an adjacency-list representation of graph
 * @param v number of vertices
 * @return pointer to graph
 */
graph_adj_list *graph_adj_list_ctor(int v);

/**
 * Destroy an adjacency-list representation of graph
 * @param graph adjacent list representation of a graph
 */
int graph_adj_list_dtor(graph_adj_list *graph);

/**
 * Add a edge to a adjacent list representation graph
 * @param graph adjacent list representation of a graph
 * @param edge undirected edge
 */
int add_undirected_edge(graph_adj_list *graph, const edge *edge);

/**
 * Add a directed edge to a adjacent list representation graph
 * @param graph adjacent list representation of a graph
 * @param edge directed edge
 */
int add_directed_edge(graph_adj_list *graph, const edge *edge);

/**
 * Add a weighted undirected edge to a adjacent list representation graph
 * @param graph adjacent list representation of a graph
 * @param weight_edge weighted undirected edge
 */
int add_weighted_undirected_edge(graph_adj_list *graph, const weighted_edge *weight_edge);

/**
 * Add a weighted directed edge to a adjacent list representation graph
 * @param graph adjacent list representation of a graph
 * @param weight_edge weighted directed edge
 */
int add_weighted_directed_edge(graph_adj_list *graph, const weighted_edge *weight_edge);

#endif // ADJACENCY_LIST_H
