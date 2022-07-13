#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include "../../10 Elementary Data Structures/binary_tree/binary_tree.h"

typedef bintree_node binstree_node;

typedef binstree_node *binstree;

/**
 * Search for a node with a given key in a binary search tree
 * @param root pointer to the root of a binary search tree or its subtrees
 * @param key a given key value
 * @return pointer to node
 */
binstree_node *binstree_search(const binstree *root, int key);

/**
 * Return an element in a binary search tree whose key is a minimum
 * @param root pointer to the root of a binary search tree or its subtrees
 * @return pointer to node
 */
binstree_node *binstree_minimum(const binstree *root);

/**
 * Return an element in a binary search tree whose key is a maximum
 * @param root pointer to the root of a binary search tree or its subtrees
 * @return pointer to node
 */
binstree_node *binstree_maximum(const binstree *root);

/**
 * Return the successor of a node as the next node visited in an inorder traversal
 * @param node pointer to a given node of binary search tree
 * @return pointer to node
 */
binstree_node *binstree_successor(const binstree_node *node);

/**
 * Return the predecessor of a node as the previous node visited in an inorder traversal
 * @param node pointer to a given node of binary search tree
 * @return pointer to node
 */
binstree_node *binstree_predecessor(const binstree_node *node);

/**
 * Insert a new node with given key value into a binary search tree
 * @param root pointer to the root of a binary search tree
 * @param key a given key value
 */
int binstree_insert(binstree *root, int key);

/**
 * Delete a node in a binary search tree
 * @param root pointer to the root of a binary search tree
 * @param node double pointer to the node to delete
 */
int binstree_delete(binstree *root, binstree_node **node);

#endif // BINARY_SEARCH_TREE_H
