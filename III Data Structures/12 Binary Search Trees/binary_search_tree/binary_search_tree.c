#include "binary_search_tree.h"
#include <stdlib.h>

/**
 * Initialize a binary (search) tree node
 * @return pointer to the binary tree node
 */
static binstree_node *binstree_node_ctor(int key);

/**
 * Replaces one subtree as a child of its parent with another subtree.
 * @param root
 * @param u pointer to the     one subtree's root
 * @param v pointer to the another subtree's root
 */
static int transplant(binstree *root, binstree_node *u, binstree_node *v);

binstree_node *binstree_search(const binstree *root, int key)
{
    binstree_node *p = (binstree_node *)(*root);
    while (p != NULL && p->key != key)
    {
        if (p->key < key)
        {
            p = p->right_child;
        }
        else
        {
            p = p->left_child;
        }
    }

    return p;
}

binstree_node *binstree_minimum(const binstree *root)
{
    if (*root != NULL)
    {
        binstree_node *p = (binstree_node *)(*root);
        while (p->left_child != NULL)
        {
            p = p->left_child;
        }

        return p;
    }
    else
    {
        return NULL;
    }
}

binstree_node *binstree_maximum(const binstree *root)
{
    if (*root != NULL)
    {
        binstree_node *p = (binstree_node *)(*root);
        while (p->right_child != NULL)
        {
            p = p->right_child;
        }

        return p;
    }
    else
    {
        return NULL;
    }
}

binstree_node *binstree_successor(const binstree_node *node)
{
    if (node->right_child != NULL)
    {
        return binstree_minimum(&(node->right_child));
    }
    else
    {
        binstree_node *ancestor = node->parent;
        binstree_node *p = (binstree_node *)node;
        while (ancestor != NULL && p == ancestor->right_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

binstree_node *binstree_predecessor(const binstree_node *node)
{
    if (node->left_child != NULL)
    {
        return binstree_minimum(&(node->left_child));
    }
    else
    {
        binstree_node *ancestor = node->parent;
        binstree_node *p = (binstree_node *)node;
        while (ancestor != NULL && p == ancestor->left_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

int binstree_insert(binstree *root, int key)
{
    const binstree_node *p = *root; // pointer to the node being compared with new node
    binstree_node *parent = NULL;   // pointer to the parent of the new node

    while (p != NULL) // descend until reaching a leaf
    {
        parent = (binstree_node *)p;
        if (key < p->key)
        {
            p = p->left_child;
        }
        else
        {
            p = p->right_child;
        }
    }

    binstree_node *node = binstree_node_ctor(key);
    node->parent = parent; // found the location—insert node with parent

    if (parent == NULL)
    {
        *root = node; // tree was empty
    }
    else if (key < parent->key)
    {
        parent->left_child = node;
    }
    else
    {
        parent->right_child = node;
    }

    return 0;
}

int binstree_delete(binstree *root, binstree_node **node)
{
    if ((*node)->left_child == NULL)
    {
        transplant(root, *node, (*node)->right_child); // replace node by its right child

        free(*node);
        *node = NULL;
    }
    else if ((*node)->right_child == NULL)
    {
        transplant(root, *node, (*node)->left_child); // replace node by its left child

        free(*node);
        *node = NULL;
    }
    else
    {
        binstree_node *p = binstree_minimum(&((*node)->right_child)); // p is node’s successor
        if (p != (*node)->right_child)                                // is p farther down the tree?
        {
            transplant(root, p, p->right_child);   // replace p by its right child
            p->right_child = (*node)->right_child; // node’s right child becomes
            p->right_child->parent = p;            // p’s right child
        }
        else
        {
            /* do nothing */
        }
        transplant(root, *node, p);          // replace node by its successor p
        p->left_child = (*node)->left_child; // and give node’s left child to p
        p->left_child->parent = p;           // which had no left child

        free(*node);
        *node = NULL;
    }

    return 0;
}

static binstree_node *binstree_node_ctor(int key)
{
    binstree_node *node = (binstree_node *)malloc(sizeof(binstree_node));
    node->key = key;
    node->parent = NULL;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

static int transplant(binstree *root, binstree_node *u, binstree_node *v)
{
    if (u->parent == NULL)
    {
        *root = v;
    }
    else if (u == u->parent->left_child)
    {
        u->parent->left_child = v;
    }
    else
    {
        u->parent->right_child = v;
    }

    if (v != NULL)
    {
        v->parent = u->parent;
    }
    else
    {
        /* do nothing */
    }

    return 0;
}
