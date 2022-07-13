#if !defined(RED_BLACK_TREE_H)
#define RED_BLACK_TREE_H

typedef enum red_black_tree_node_color
{
    RED,
    BLACK
} rbtree_node_color;

typedef struct red_black_tree_node
{
    enum red_black_tree_node_color color;
    int key;
    struct red_black_tree_node *left_child;
    struct red_black_tree_node *right_child;
    struct red_black_tree_node *parent;
} rbtree_node;

typedef struct rbtree
{
    rbtree_node *root;
    rbtree_node *sentinel;
} rbtree;

/**
 * Initialize a red-black tree
 * @return pointer to the red-black tree
 */
rbtree *rbtree_ctor();

/**
 * Destroy a red-black tree
 * @param tree double pointer to the red-black tree
 */
int rbtree_dtor(rbtree **tree);

/**
 * Preorder traversal of red-black tree
 * @param tree pointer to the red-black tree
 * @param root pointer to the root of red-black tree
 */
void rbtree_preorder_traversal(const rbtree *tree, rbtree_node *root);

/**
 * Inorder traversal of red-black tree
 * @param tree pointer to the red-black tree
 * @param root pointer to the root of red-black tree
 */
void rbtree_inorder_traversal(const rbtree *tree, rbtree_node *root);

/**
 * Postorder traversal of red-black tree
 * @param tree pointer to the red-black tree
 * @param root pointer to the root of red-black tree
 */
void rbtree_postorder_traversal(const rbtree *tree, rbtree_node *root);

/**
 * Search for a node with a given key in red-black tree
 * @param tree pointer to the red-black tree
 * @param key a given key value
 * @return pointer to node
 */
rbtree_node *rbtree_search(const rbtree *tree, int key);

/**
 * Return an element in a red-black tree  whose key is a minimum
 * @param tree pointer to the red-black tree
 * @param root pointer to the root of a red-black tree or its subtrees
 * @return pointer to the node with minimum key value
 */
rbtree_node *rbtree_minimum(const rbtree *tree, const rbtree_node *root);

/**
 * Return an element in a red-black tree  whose key is a maximum
 * @param tree pointer to the red-black tree
 * @param root pointer to the root of a red-black tree or its subtrees
 * @return pointer to the node with maximum key value
 */
rbtree_node *rbtree_maximum(const rbtree *tree, const rbtree_node *root);

/**
 * Return the successor of a node as the next node visited in an inorder traversal
 * @param tree pointer to the red-black tree
 * @param node pointer to node
 * @return pointer to the successor of node
 */
rbtree_node *rbtree_successor(const rbtree *tree, const rbtree_node *node);

/**
 * Return the predecessor of a node as the previous node visited in an inorder traversal
 * @param tree pointer to the red-black tree
 * @param node pointer to node
 * @return pointer to the predecessor of node
 */
rbtree_node *rbtree_predecessor(const rbtree *tree, const rbtree_node *node);

/**
 * Insert a new node in the red-black tree
 * @param tree pointer to the red-black tree
 * @param key key value of new node
 */
int rbtree_insert(rbtree *tree, int key);

/**
 * Delete a node in the red-black tree
 * @param tree pointer to the red-black tree
 * @param node double pointer to the node
 */
int rbtree_delete(rbtree *tree, rbtree_node **node);

#endif // RED_BLACK_TREE_H
