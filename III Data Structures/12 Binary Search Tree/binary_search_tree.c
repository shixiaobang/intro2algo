#include "binary_search_tree.h"
#include <stdlib.h>

/**
 * Initialize a binary (search) tree node
 * @return pointer to the binary tree node
 */
static binst_node *binst_node_ctor(int key);

/**
 * Replaces one subtree as a child of its parent with another subtree.
 * @param root
 * @param u pointer to the     one subtree's root
 * @param v pointer to the another subtree's root
 */
static int transplant(binst *root, binst_node *u, binst_node *v);

binst_node *binst_search(const binst *root, int key)
{
    binst_node *p = (binst_node *)(*root);
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

binst_node *binst_minimum(const binst *root)
{
    if (*root != NULL)
    {
        binst_node *p = (binst_node *)(*root);
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

binst_node *binst_maximum(const binst *root)
{
    if (*root != NULL)
    {
        binst_node *p = (binst_node *)(*root);
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

binst_node *binst_successor(const binst_node *node)
{
    if (node->right_child != NULL)
    {
        return binst_minimum(&(node->right_child));
    }
    else
    {
        binst_node *ancestor = node->parent;
        binst_node *p = (binst_node *)node;
        while (ancestor != NULL && p == ancestor->right_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

binst_node *binst_predecessor(const binst_node *node)
{
    if (node->left_child != NULL)
    {
        return binst_minimum(&(node->left_child));
    }
    else
    {
        binst_node *ancestor = node->parent;
        binst_node *p = (binst_node *)node;
        while (ancestor != NULL && p == ancestor->left_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

int binst_insert(binst *root, int key)
{
    const binst_node *p = *root; // pointer to the node being compared with new node
    binst_node *parent = NULL;   // pointer to the parent of the new node

    while (p != NULL) // descend until reaching a leaf
    {
        parent = (binst_node *)p;
        if (key < p->key)
        {
            p = p->left_child;
        }
        else
        {
            p = p->right_child;
        }
    }

    binst_node *node = binst_node_ctor(key);
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

int binst_delete(binst *root, binst_node **node)
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
        binst_node *p = binst_minimum(&((*node)->right_child)); // p is node’s successor
        if (p != (*node)->right_child)                          // is p farther down the tree?
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

static binst_node *binst_node_ctor(int key)
{
    binst_node *node = (binst_node *)malloc(sizeof(binst_node));
    node->key = key;
    node->parent = NULL;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

static int transplant(binst *root, binst_node *u, binst_node *v)
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
