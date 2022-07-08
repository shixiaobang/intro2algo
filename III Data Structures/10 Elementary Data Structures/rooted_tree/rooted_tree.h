#if !defined(ROOTED_TREE_H)
#define ROOTED_TREE_H

typedef struct rooted_tree_node
{
    int key;
    struct rooted_tree_node *parent;
    struct rooted_tree_node *left_child;
    struct rooted_tree_node *right_sibling;
} rt_node;

typedef rt_node *rt;

/**
 * Initialize a rooted tree
 * @return pointer to the root of rooted tree
 */
rt *rt_ctor();

/**
 * Destroy a rooted tree
 * @param pointer to the root of rooted tree
 */
int rt_dtor(rt *root);

#endif // ROOTED_TREE_H
