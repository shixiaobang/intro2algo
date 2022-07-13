#include "rooted_tree.h"
#include <stdlib.h>

rtree *rtree_ctor()
{
    rtree *root = (rtree *)malloc(sizeof(rtree));
    *root = NULL;

    return root;
}

int rtree_dtor(rtree *root)
{
    if (*root != NULL)
    {
        rtree_dtor(&((*root)->left_child));
        rtree_dtor(&((*root)->right_sibling));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
