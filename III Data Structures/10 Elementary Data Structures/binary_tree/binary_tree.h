#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

typedef struct binary_tree_node
{
    int key;
    struct binary_tree_node *parent;
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
} bintree_node;

typedef bintree_node *bintree;

/**
 * Initialize a binary tree
 * @return pointer to the root of binary tree
 */
bintree *bintree_ctor();

/**
 * Destroy a binary tree
 * @param root pointer to the root of binary tree
 */
int bintree_dtor(bintree **root);

/**
 * Preorder traversal of binary tree
 * @param root pointer to the root of a binary tree or its subtrees
 */
void bintree_preorder_traversal(const bintree *root);

/**
 * Inorder traversal of binary tree
 * @param root pointer to the root of a binary tree or its subtrees
 */
void bintree_inorder_traversal(const bintree *root);

/**
 * Postorder traversal of binary tree
 * @param root pointer to the root of a binary tree or its subtrees
 */
void bintree_postorder_traversal(const bintree *root);

#endif // BINARY_TREE_H
