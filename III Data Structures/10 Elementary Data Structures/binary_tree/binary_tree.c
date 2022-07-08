#include "binary_tree.h"
#include <stdlib.h>

bint *bint_ctor()
{
    bint *root = (bint *)malloc(sizeof(bint));
    *root = NULL;

    return root;
}

int bint_dtor(bint *root)
{
    if (*root != NULL)
    {
        bint_dtor(&((*root)->left_child));
        bint_dtor(&((*root)->right_child));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
