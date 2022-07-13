#include "graph_adjacency_list.h"
#include <stdlib.h>

graph_alist *graph_alist_ctor(const int v)
{
    graph_alist *graph = (graph_alist *)malloc(sizeof(graph_alist));
    if (graph != NULL)
    {
        graph->head = alist_array_ctor(v);
        graph->v = v;
        graph->e = 0;
    }

    return graph;
}

int graph_alist_dtor(graph_alist **graph)
{
    alist_array_dtor(&((*graph)->head), (*graph)->v); // free adjacency list array

    free(*graph);
    *graph = NULL;

    return 0;
}

int graph_alist_add_ue(graph_alist *graph, const int u, const int v)
{
    alist_prepend(graph->head + v, u); // prepend u to head[v]
    alist_prepend(graph->head + u, v); // prepend v to head[u]

    graph->e += 1;

    return 0;
}

int graph_alist_add_de(graph_alist *graph, const int u, const int v)
{
    alist_prepend(graph->head + u, v); // prepend u to head[v]

    graph->e += 1;

    return 0;
}
