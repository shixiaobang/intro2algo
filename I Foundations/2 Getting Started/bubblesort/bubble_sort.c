#include "bubble_sort.h"

/**
 * Swap two integers
 * @param x     one integer
 * @param y another integer
 */
static int swap(int *x, int *y);

int bubble_sort(int *array, int n)
{
    if (n != 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (*(array + j) > *(array + j + 1))
                {
                    swap(array + j, array + j + 1);
                }
            }
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

static int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    return 0;
}
