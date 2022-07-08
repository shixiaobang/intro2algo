#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

typedef struct binary_tree_node
{
    int key;
    struct binary_tree_node *parent;
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
} bint_node;

typedef bint_node *bint;

/**
 * Initialize a binary tree
 * @return pointer to the root of binary tree
 */
bint *bint_ctor();

/**
 * Destroy a binary tree
 * @param root pointer to the root of binary tree
 */
int bint_dtor(bint *root);

#endif // BINARY_TREE_H
