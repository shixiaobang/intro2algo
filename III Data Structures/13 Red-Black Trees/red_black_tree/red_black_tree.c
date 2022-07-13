#include "red_black_tree.h"
#include <stdlib.h>

/**
 * Initialize a red-black tree node
 * @param color color of node
 * @param key key value of node
 * @return pointer to red-black tree node
 */
static rbtree_node *rbtree_node_ctor(rbtree_node_color color, int key);

/**
 * Destroy all nodes of red-black tree (Postorder)
 * @param tree pointer to red-black tree
 * @param root double pointer to the root of tree
 */
static int rbtree_nodes_dtor(rbtree *tree, rbtree_node **root);

/**
 * Left rotation on a node that preserves the binary-search-tree property
 * @param x pointer to a node
 */
static int left_rotate(rbtree *tree, rbtree_node *x);

/**
 * Right rotation on a node that preserves the binary-search-tree property
 * @param x pointer to a node
 */
static int right_rotate(rbtree *tree, rbtree_node *x);

/**
 * Guarantee that the red-black properties are preserved after insertion
 * @param tree pointer to red-black tree
 * @param node pointer to a node
 */
static int insert_fixup(rbtree *tree, rbtree_node *node);

/**
 * Replaces the subtree rooted at node u by the subtree rooted at node v
 * @param tree pointer to the red-black tree
 * @param u pointer to the     one subtree's root
 * @param v pointer to the another subtree's root
 */
static int transplant(rbtree *tree, rbtree_node *u, rbtree_node *v);

/**
 * Guarantee that the red-black properties are preserved after deletion
 * @param tree pointer to red-black tree
 * @param node pointer to a node
 */
static int delete_fixup(rbtree *tree, rbtree_node *node);

rbtree *rbtree_ctor()
{
    rbtree *tree = (rbtree *)malloc(sizeof(rbtree));

    tree->sentinel = (rbtree_node *)malloc(sizeof(rbtree_node));
    tree->sentinel->color = BLACK;
    tree->sentinel->left_child = NULL;
    tree->sentinel->right_child = NULL;
    tree->sentinel->parent = NULL;

    tree->root = tree->sentinel;

    return tree;
}

int rbtree_dtor(rbtree **tree)
{
    rbtree_nodes_dtor(*tree, &((*tree)->root));

    free((*tree)->sentinel);
    (*tree)->sentinel = NULL;

    free(*tree);
    *tree = NULL;

    return 0;
}

void rbtree_preorder_traversal(const rbtree *tree, rbtree_node *root)
{
    if (root != tree->sentinel)
    {
        /* do something on node at here */
        // if (root->color == RED) {} else {}
        rbtree_preorder_traversal(tree, root->left_child);
        rbtree_preorder_traversal(tree, root->right_child);
    }
    else
    {
        return;
    }
}

void rbtree_inorder_traversal(const rbtree *tree, rbtree_node *root)
{
    if (root != tree->sentinel)
    {

        rbtree_inorder_traversal(tree, root->left_child);
        /* do something on node at here */
        // if (root->color == RED) {} else {}
        rbtree_inorder_traversal(tree, root->right_child);
    }
    else
    {
        return;
    }
}

void rbtree_postorder_traversal(const rbtree *tree, rbtree_node *root)
{
    if (root != tree->sentinel)
    {

        rbtree_postorder_traversal(tree, root->left_child);
        rbtree_postorder_traversal(tree, root->right_child);
        /* do something on node at here */
        // if (root->color == RED) {} else {}
    }
    else
    {
        return;
    }
}

rbtree_node *rbtree_search(const rbtree *tree, int key)
{
    rbtree_node *p = (rbtree_node *)(tree->root);
    while (p != tree->sentinel && p->key != key)
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

rbtree_node *rbtree_minimum(const rbtree *tree, const rbtree_node *root)
{
    if (root != tree->sentinel)
    {
        rbtree_node *p = (rbtree_node *)root;
        while (p->left_child != tree->sentinel)
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

rbtree_node *rbtree_maximum(const rbtree *tree, const rbtree_node *root)
{
    if (root != tree->sentinel)
    {
        rbtree_node *p = (rbtree_node *)root;
        while (p->right_child != tree->sentinel)
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

rbtree_node *rbtree_successor(const rbtree *tree, const rbtree_node *node)
{
    if (node->right_child != tree->sentinel)
    {
        return rbtree_minimum(tree, node->right_child);
    }
    else
    {
        rbtree_node *ancestor = node->parent;
        rbtree_node *p = (rbtree_node *)node;
        while (ancestor != tree->sentinel && p == ancestor->right_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

rbtree_node *rbtree_predecessor(const rbtree *tree, const rbtree_node *node)
{
    if (node->left_child != tree->sentinel)
    {
        return rbtree_minimum(tree, node->left_child);
    }
    else
    {
        rbtree_node *ancestor = node->parent;
        rbtree_node *p = (rbtree_node *)node;
        while (ancestor != tree->sentinel && p == ancestor->left_child)
        {
            p = ancestor;
            ancestor = ancestor->parent;
        }

        return ancestor;
    }
}

int rbtree_insert(rbtree *tree, int key)
{
    rbtree_node *x = tree->root;                    // node being compared with z (new node)
    rbtree_node *y = tree->sentinel;                // y will be parent of z
    rbtree_node *node = rbtree_node_ctor(RED, key); // the new node starts out red
    while (x != tree->sentinel)                     // descend until reaching the sentinel
    {
        y = x;
        if (node->key < x->key)
        {
            x = x->left_child;
        }
        else
        {
            x = x->right_child;
        }
    }
    node->parent = y; // found the location—insert z with parent y
    if (y == tree->sentinel)
    {
        tree->root = node; // tree T was empty
    }
    else if (node->key < y->key)
    {
        y->left_child = node;
    }
    else
    {
        y->right_child = node;
    }
    node->left_child = tree->sentinel; // both of z’s children are the sentinel
    node->right_child = tree->sentinel;

    insert_fixup(tree, node); // correct any violations of red-black properties

    return 0;
}

int rbtree_delete(rbtree *tree, rbtree_node **node)
{
    rbtree_node *x = NULL;
    rbtree_node *y = *node;
    rbtree_node_color y_original_color = y->color;
    if ((*node)->left_child == tree->sentinel)
    {
        x = (*node)->right_child;
        transplant(tree, *node, (*node)->right_child);
    }
    else if ((*node)->right_child == tree->sentinel)
    {
        x = (*node)->left_child;
        transplant(tree, *node, (*node)->left_child);
    }
    else
    {
        y = rbtree_minimum(tree, (*node)->right_child);
        y_original_color = y->color;
        x = y->right_child;
        if (y != (*node)->right_child)
        {
            transplant(tree, y, y->right_child);
            y->right_child = (*node)->right_child;
            y->right_child->parent = y;
        }
        else
        {
            x->parent = y;
        }
        transplant(tree, *node, y);
        y->left_child = (*node)->left_child;
        y->left_child->parent = y;
        y->color = (*node)->color;
    }

    if (y_original_color == BLACK)
    {
        delete_fixup(tree, x);
    }
    else
    {
        /* do nothing */
    }

    free(*node);
    *node = NULL;

    return 0;
}

static rbtree_node *rbtree_node_ctor(rbtree_node_color color, int key)
{
    rbtree_node *node = (rbtree_node *)malloc(sizeof(rbtree_node));
    node->color = color;
    node->key = key;
    node->left_child = NULL;
    node->right_child = NULL;
    node->parent = NULL;

    return node;
}

static int rbtree_nodes_dtor(rbtree *tree, rbtree_node **root)
{
    if (*root != tree->sentinel)
    {
        rbtree_nodes_dtor(tree, &((*root)->left_child));
        rbtree_nodes_dtor(tree, &((*root)->right_child));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}

static int left_rotate(rbtree *tree, rbtree_node *x)
{
    rbtree_node *y = x->right_child;
    x->right_child = y->left_child;      // turn y’s right subtree into x’s left subtree
    if (y->left_child != tree->sentinel) // if y’s right subtree is not empty
    {
        y->left_child->parent = x; // then x becomes the parent of the subtree’s root
    }
    else
    {
        /* do nothing */
    }
    y->parent = x->parent;           // x’s parent becomes y’s parent
    if (x->parent == tree->sentinel) // if x was the root
    {
        tree->root = y; // then y becomes the root
    }
    else if (x == x->parent->left_child) // otherwise, if x was a right child
    {
        x->parent->left_child = y; // then y becomes a right child
    }
    else
    {
        x->parent->right_child = y; // otherwise, x was a left child, and now y is
    }
    y->left_child = x; // make x become y’s right child
    x->parent = y;

    return 0;
}

static int right_rotate(rbtree *tree, rbtree_node *x)
{
    rbtree_node *y = x->left_child;
    x->left_child = y->right_child;       // turn y’s right subtree into x’s left subtree
    if (y->right_child != tree->sentinel) // if y’s right subtree is not empty
    {
        y->right_child->parent = x; // then x becomes the parent of the subtree’s root
    }
    else
    {
        /* do nothing */
    }
    y->parent = x->parent;           // x’s parent becomes y’s parent
    if (x->parent == tree->sentinel) // if x was the root
    {
        tree->root = y; // then y becomes the root
    }
    else if (x == x->parent->right_child) // otherwise, if x was a right child
    {
        x->parent->right_child = y; // then y becomes a right child
    }
    else
    {
        x->parent->left_child = y; // otherwise, x was a left child, and now y is
    }
    y->right_child = x; // make x become y’s right child
    x->parent = y;

    return 0;
}

static int insert_fixup(rbtree *tree, rbtree_node *node)
{
    rbtree_node *uncle = NULL; // new node’s (z's) uncle
    while (node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left_child)
        {
            uncle = node->parent->parent->right_child;
            if (uncle->color == RED) // are z’s parent and uncle both red?
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right_child)
                {
                    node = node->parent;
                    left_rotate(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(tree, node->parent->parent);
            }
        }
        else // same as above, but with “right” and “left” exchanged
        {
            uncle = node->parent->parent->left_child;
            if (uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left_child)
                {
                    node = node->parent;
                    right_rotate(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;

    return 0;
}

static int transplant(rbtree *tree, rbtree_node *u, rbtree_node *v)
{
    if (u->parent == tree->sentinel)
    {
        tree->root = v;
    }
    else if (u == u->parent->left_child)
    {
        u->parent->left_child = v;
    }
    else
    {
        u->parent->right_child = v;
    }
    v->parent = u->parent;

    return 0;
}

static int delete_fixup(rbtree *tree, rbtree_node *node)
{
    rbtree_node *w = NULL;
    while (node != tree->root && node->color == BLACK)
    {
        if (node == node->parent->left_child)
        {
            w = node->parent->right_child; // w is x’s sibling
            if (w->color == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                left_rotate(tree, node->parent);
                w = node->parent->right_child;
            }
            if (w->left_child->color == BLACK && w->right_child->color == BLACK)
            {
                w->color == RED;
                node = node->parent;
            }
            else
            {
                if (w->right_child->color == BLACK)
                {
                    w->left_child->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = node->parent->right_child;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->right_child->color = BLACK;
                left_rotate(tree, node->parent);
                node = tree->root;
            }
        }
        else
        {
            w = node->parent->left_child;
            if (w->color == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                right_rotate(tree, node->parent);
                w = node->parent->left_child;
            }
            if (w->right_child->color == BLACK && w->left_child->color == BLACK)
            {
                w->color = RED;
                node = node->parent;
            }
            else
            {
                if (w->left_child->color == BLACK)
                {
                    w->right_child->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = node->parent->left_child;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->left_child->color = BLACK;
                right_rotate(tree, node->parent);
                node = tree->root;
            }
        }

        node->color = BLACK;

        return 0;
    }
}
