#include "weighted_graph_adjacency_list.h"
#include <stdlib.h>

graph_walist *graph_walist_ctor(const int v)
{
    graph_walist *graph = (graph_walist *)malloc(sizeof(graph_walist));
    if (graph != NULL)
    {
        graph->head = walist_array_ctor(v);
        graph->v = v;
        graph->e = 0;
    }

    return graph;
}

int graph_walist_dtor(graph_walist **graph)
{
    walist_array_dtor(&((*graph)->head), (*graph)->v); // free adjacent list array of weighted graph

    free(*graph);
    *graph = NULL;

    return 0;
}

int graph_walist_add_ue(graph_walist *graph, const int u, const int v, const int weight)
{
    walist_prepend(graph->head + v, u, weight); // prepend u with edge weight to head[v]
    walist_prepend(graph->head + u, v, weight); // prepend v with edge weight to head[u]

    graph->e += 1;

    return 0;
}

int graph_walist_add_de(graph_walist *graph, const int u, const int v, const int weight)
{
    walist_prepend(graph->head + u, v, weight); // prepend u with edge weight to head[v]

    graph->e += 1;

    return 0;
}
