#include "weighted_graph_adjacency_list.h"
#include <stdlib.h>

graph_wal *graph_wal_ctor(const int v)
{
    graph_wal *graph = (graph_wal *)malloc(sizeof(graph_wal));
    if (graph != NULL)
    {
        graph->head = wal_array_ctor(v);
        graph->v = v;
        graph->e = 0;
    }

    return graph;
}

int graph_wal_dtor(graph_wal **graph)
{
    wal_array_dtor(&((*graph)->head), (*graph)->v); // free adjacent list array of weighted graph

    free(*graph);
    *graph = NULL;

    return 0;
}

int graph_wal_add_ue(graph_wal *graph, const int u, const int v, const int weight)
{
    wal_prepend(graph->head + v, u, weight); // prepend u with edge weight to head[v]
    wal_prepend(graph->head + u, v, weight); // prepend v with edge weight to head[u]

    graph->e += 1;

    return 0;
}

int graph_wal_add_de(graph_wal *graph, const int u, const int v, const int weight)
{
    wal_prepend(graph->head + u, v, weight); // prepend u with edge weight to head[v]

    graph->e += 1;

    return 0;
}
