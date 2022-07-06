#if !defined(EDGE_H)
#define EDGE_H

typedef struct edge
{
    int u; // index of edge's one endpoint (undirected graph) or initial vertex (directed graph)
    int v; // index of edge's another endpoint (undirected graph) or terminal vertex (directed graph)
} edge;

typedef struct weighted_edge
{
    int u;      // index of edge's one vertex
    int v;      // index of edge's another vertex
    int weight; // weight of undirected or directed edge
} weighted_edge;

/**
 * Initialize an edge
 * @param u  index of edge's one vertex
 * @param v  index of edge's another vertex
 * @return pointer to edge
 */
edge *edge_ctor(int u, int v);

/**
 * Destroy an edge
 * @param edge pointer to an edge
 */
int edge_dtor(struct edge **edge);

/**
 * Initialize an weighted edge
 * @param u  index of edge's one vertex
 * @param v  index of edge's another vertex
 * @param weight weight of edge
 * @return pointer to weighted edge
 */
weighted_edge *weighted_edge_ctor(int u, int v, int weight);

/**
 * Destroy an weighted edge
 * @param weighted_edge pointer to an weighted edge's pointer
 */
int weighted_edge_dtor(struct weighted_edge **weighted_edge);

#endif // EDGE_H
