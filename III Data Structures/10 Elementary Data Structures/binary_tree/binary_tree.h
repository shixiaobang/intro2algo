#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

typedef struct binary_tree_node
{
    int key;
    struct binary_tree_node *parent;
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
} binary_tree_node;

typedef binary_tree_node *binary_tree;

binary_tree *binary_tree_ctor();

int binary_tree_dtor(binary_tree *root);

#endif // BINARY_TREE_H
