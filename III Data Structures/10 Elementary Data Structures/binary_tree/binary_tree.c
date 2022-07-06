#include "binary_tree.h"
#include <stdlib.h>

binary_tree *binary_tree_ctor()
{
    binary_tree *root = (binary_tree *)malloc(sizeof(binary_tree));
    *root = NULL;

    return root;
}

int binary_tree_dtor(binary_tree *root)
{
    if (*root != NULL)
    {
        binary_tree_dtor(&((*root)->left_child));
        binary_tree_dtor(&((*root)->right_child));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
