#include "adjacency_list.h"
#include <stdlib.h>

/**
 * @param index index of vertex
 * @return pointer to vertex
 */
vertex *vertex_ctor(int index);

/**
 * @param head double pointer to head of adjacency list
 * @param index index of vertex
 */
int vertex_prepend(vertex **head, int index);

graph_adj_list *graph_adj_list_ctor(int v)
{
    graph_adj_list *graph = (graph_adj_list *)malloc(sizeof(graph_adj_list));
    if (graph != NULL)
    {
        graph->v = v;
        graph->e = 0;

        graph->list = (vertex **)malloc(sizeof(vertex *) * v);
        if (graph->list != NULL)
        {
            for (int i = 0; i < v; i++)
            {
                *(graph->list + i) = NULL;
            }

            return graph;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

int graph_adj_list_dtor(graph_adj_list *graph)
{
    vertex **head;   // head of vertices
    const vertex *p; // pointer to vertex
    for (int i = 0; i < graph->v; i++)
    {
        head = (graph->list + i);
        if (*head != NULL)
        {
            p = (*head)->next;
            while (p != NULL)
            {
                free(*head);
                *head = NULL;

                *head = (vertex *)p;
                p = (*head)->next;
            }
            free(*head);
            *head = NULL;
        }
        else
        {
            /* do nothing */
        }
    }

    free(graph->list);
    graph->list = NULL;

    free(graph);
    /* graph = NULL; */

    return 0;
}

int add_undirected_edge(graph_adj_list *graph, const edge *edge)
{
    int u = edge->u;
    int v = edge->v;

    vertex_prepend(graph->list + u, v); // add u to list[v]
    vertex_prepend(graph->list + v, u); // add v to list[u]

    graph->e += 1;

    return 0;
}

int add_directed_edge(graph_adj_list *graph, const edge *edge)
{
}

int add_weighted_undirected_edge(graph_adj_list *graph, const weighted_edge *weight_edge)
{
}

int add_weighted_directed_edge(graph_adj_list *graph, const weighted_edge *weight_edge)
{
}

vertex *vertex_ctor(int index)
{
    vertex *v = (vertex *)malloc(sizeof(vertex));
    v->index = index;
    v->next = NULL;

    return v;
}

int vertex_prepend(vertex **head, int index)
{
    vertex *v = vertex_ctor(index);
    if (*head != NULL)
    {
        *head = v;
    }
    else
    {
        v->next = *head;
        *head = v;
    }
    return 0;
}