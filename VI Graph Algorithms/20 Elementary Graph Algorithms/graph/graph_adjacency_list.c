#include "graph_adjacency_list.h"
#include <stdlib.h>

graph_al *graph_al_ctor(const int v)
{
    graph_al *graph = (graph_al *)malloc(sizeof(graph_al));
    if (graph != NULL)
    {
        graph->head = al_array_ctor(v);
        graph->v = v;
        graph->e = 0;
    }

    return graph;
}

int graph_al_dtor(graph_al **graph)
{
    al_array_dtor(&((*graph)->head), (*graph)->v); // free adjacency list array

    free(*graph);
    *graph = NULL;

    return 0;
}

int graph_al_add_ue(graph_al *graph, const int u, const int v)
{
    al_prepend(graph->head + v, u); // prepend u to head[v]
    al_prepend(graph->head + u, v); // prepend v to head[u]

    graph->e += 1;

    return 0;
}

int graph_al_add_de(graph_al *graph, const int u, const int v)
{
    al_prepend(graph->head + u, v); // prepend u to head[v]

    graph->e += 1;

    return 0;
}
