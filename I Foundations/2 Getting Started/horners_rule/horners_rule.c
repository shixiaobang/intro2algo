#include "horners_rule.h"

int horner(int *array, int n, int x)
{
    int p = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        p = *(array + i) + x * p;
    }

    return p;
}
