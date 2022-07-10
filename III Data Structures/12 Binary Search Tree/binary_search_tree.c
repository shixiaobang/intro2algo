#include "binary_search_tree.h"
#include <stdlib.h>

/**
 * Initialize a binary tree node
 * @return pointer to the binary tree node
 */
static binst_node *binst_node_ctor(int key);

/**
 * TODO
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

binst_node *binst_successor(const binst *node)
{
    if ((*node)->right_child != NULL)
    {
        return binst_minimum(&((*node)->right_child));
    }
    else
    {
        binst_node *ancestor = (*node)->parent;
        binst_node *p = (binst_node *)*node;
        while (ancestor != NULL && p == ancestor->right_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

binst_node *binst_predecessor(const binst *node)
{
    if ((*node)->left_child != NULL)
    {
        return binst_minimum(&((*node)->left_child));
    }
    else
    {
        binst_node *ancestor = (*node)->parent;
        binst_node *p = (binst_node *)*node;
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

    while (p != NULL)
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
    node->parent = parent;

    if (parent == NULL)
    {
        *root = node;
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
    /* TODO */
}
