#include "binary_tree.h"
#include <stdlib.h>

/**
 * Destroy a subtree of binary tree (Postorder)
 * @param root pointer to the root of subtree
 */
static int subtree_dtor(bint *root);

bint *bint_ctor()
{
    bint *root = (bint *)malloc(sizeof(bint));
    *root = NULL;

    return root;
}

int bint_dtor(bint **root)
{
    bint *left_root = &((**root)->left_child);   // pointer to the left subtree of root
    bint *right_root = &((**root)->right_child); // pointer to the right subtree of root

    subtree_dtor(left_root);
    subtree_dtor(right_root);

    free(**root);
    **root = NULL;

    free(*root);
    *root = NULL;

    return 0;
}

void bint_preorder_traversal(const bint *root)
{
    if (*root != NULL)
    {
        /* do something on (*root) at here */
        bint_preorder_traversal(&((*root)->left_child));
        bint_preorder_traversal(&((*root)->right_child));
    }
    else
    {
        return;
    }
}

void bint_inorder_traversal(const bint *root)
{
    if (*root != NULL)
    {
        bint_inorder_traversal(&((*root)->left_child));
        /* do something on (*root) at here */
        bint_inorder_traversal(&((*root)->right_child));
    }
    else
    {
        return;
    }
}

void bint_postorder_traversal(const bint *root)
{
    if (*root != NULL)
    {
        bint_postorder_traversal(&((*root)->left_child));
        bint_postorder_traversal(&((*root)->right_child));
        /* do something on (*root) at here */
    }
    else
    {
        return;
    }
}

static int subtree_dtor(bint *root)
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
