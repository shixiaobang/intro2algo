#if !defined(RED_BLACK_TREE_H)
#define RED_BLACK_TREE_H

typedef enum red_black_tree_node_color
{
    RED,
    BLACK
} rbt_node_color;

typedef struct red_black_tree_node
{
    enum red_black_tree_node_color color;
    int key;
    struct red_black_tree_node *left_child;
    struct red_black_tree_node *right_child;
    struct red_black_tree_node *parent;
} rbt_node;

typedef rbt_node *rbt;

/**
 * Initialize a red-black tree
 * @return pointer to the root of red-black tree
 */
rbt *rbt_ctor();

/**
 * Destroy a red-black tree
 * @param root pointer to the root of red-black tree
 */
int rbt_dtor(rbt **root);

#endif // RED_BLACK_TREE_H
