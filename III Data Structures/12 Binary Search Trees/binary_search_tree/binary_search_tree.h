#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include "../../10 Elementary Data Structures/binary_tree/binary_tree.h"

typedef bint_node binst_node;

typedef binst_node *binst;

/**
 * Search for a node with a given key in a binary search tree
 * @param root pointer to the root of a binary search tree or its subtrees
 * @param key a given key value
 */
binst_node *binst_search(const binst *root, int key);

/**
 * Return an element in a binary search tree whose key is a minimum
 * @param root pointer to the root of a binary search tree or its subtrees
 */
binst_node *binst_minimum(const binst *root);

/**
 * Return an element in a binary search tree whose key is a maximum
 * @param root pointer to the root of a binary search tree or its subtrees
 */
binst_node *binst_maximum(const binst *root);

/**
 * Return the successor of a node as the next node visited in an inorder traversal
 * @param node pointer to a given node of binary search tree
 */
binst_node *binst_successor(const binst_node *node);

/**
 * Return the predecessor of a node as the previous node visited in an inorder traversal
 * @param node pointer to a given node of binary search tree
 */
binst_node *binst_predecessor(const binst_node *node);

/**
 * Insert a new node with given key value into a binary search tree
 * @param root pointer to the root of a binary search tree
 * @param key a given key value
 */
int binst_insert(binst *root, int key);

/**
 * Delete a node in a binary search tree
 * @param root pointer to the root of a binary search tree
 * @param node double pointer to the node to delete
 */
int binst_delete(binst *root, binst_node **node);

#endif // BINARY_SEARCH_TREE_H
