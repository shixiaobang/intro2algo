#include "rooted_tree.h"
#include <stdlib.h>

rt *rt_ctor()
{
    rt *root = (rt *)malloc(sizeof(rt));
    *root = NULL;

    return root;
}

int rt_dtor(rt *root)
{
    if (*root != NULL)
    {
        rt_dtor(&((*root)->left_child));
        rt_dtor(&((*root)->right_sibling));

        free(*root);
        *root = NULL;

        return 0;
    }
    else
    {
        return 1;
    }
}
