#include "edge.h"
#include <stdlib.h>

edge *edge_ctor(int u, int v)
{
    edge *e = (edge *)malloc(sizeof(edge));

    e->u = u;
    e->v = v;

    return e;
}

int edge_dtor(struct edge **edge)
{
    free(*edge);
    *edge = NULL;

    return 0;
}

weighted_edge *weighted_edge_ctor(int u, int v, int weight)
{
    weighted_edge *w_e = (weighted_edge *)malloc(sizeof(weighted_edge));

    w_e->u = u;
    w_e->v = v;
    w_e->weight = weight;

    return w_e;
}

int weighted_edge_dtor(struct weighted_edge **weighted_edge)
{
    free(*weighted_edge);
    *weighted_edge = NULL;

    return 0;
}