#include "binary_tree.h"
#include <stdlib.h>

/**
 * Destroy a subtree of binary tree (Postorder)
 * @param root pointer to the root of subtree
 */
static int subtree_dtor(bintree *root);

bintree *bintree_ctor()
{
    bintree *root = (bintree *)malloc(sizeof(bintree));
    *root = NULL;

    return root;
}

int bintree_dtor(bintree **root)
{
    bintree *left_root = &((**root)->left_child);   // pointer to the left subtree of root
    bintree *right_root = &((**root)->right_child); // pointer to the right subtree of root

    subtree_dtor(left_root);
    subtree_dtor(right_root);

    free(**root);
    **root = NULL;

    free(*root);
    *root = NULL;

    return 0;
}

void bintree_preorder_traversal(const bintree *root)
{
    if (*root != NULL)
    {
        /* do something on (*root) at here */
        bintree_preorder_traversal(&((*root)->left_child));
        bintree_preorder_traversal(&((*root)->right_child));
    }
    else
    {
        return;
    }
}

void bintree_inorder_traversal(const bintree *root)
{
    if (*root != NULL)
    {
        bintree_inorder_traversal(&((*root)->left_child));
        /* do something on (*root) at here */
        bintree_inorder_traversal(&((*root)->right_child));
    }
    else
    {
        return;
    }
}

void bintree_postorder_traversal(const bintree *root)
{
    if (*root != NULL)
    {
        bintree_postorder_traversal(&((*root)->left_child));
        bintree_postorder_traversal(&((*root)->right_child));
        /* do something on (*root) at here */
    }
    else
    {
        return;
    }
}

static int subtree_dtor(bintree *root)
{
    if (*root != NULL)
    {
        subtree_dtor(&((*root)->left_child));
        subtree_dtor(&((*root)->right_child));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
