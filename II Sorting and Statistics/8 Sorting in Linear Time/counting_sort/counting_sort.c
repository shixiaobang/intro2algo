#include "counting_sort.h"
#include <stdlib.h>

int *counting_sort(int *array, int n, int k)
{
    // COUNTING-SORT procedure returns its sorted output in the array B[0 : n - 1]
    // and uses an array C [0 : k] for temporary working storage.

    // let B[0 : n - 1] and C [0 : k] be new arrays
    int *sorted = (int *)malloc(sizeof(int) * n);
    int *temp = (int *)malloc(sizeof(int) * (k + 1));

    for (int i = 0; i < k + 1; i++)
    {
        *(temp + i) = 0;
    }

    for (int i = 0; i < n; i++)
    {
        *(sorted + i) = 0;
    }

    for (int j = 0; j < n; j++)
    {
        *(temp + *(array + j)) += 1;
    }
    // C [i] now contains the number of elements equal to i.

    for (int i = 1; i < k + 1; i++)
    {
        *(temp + i) += *(temp + (i - 1));
    }
    // C [i] now contains the number of elements less than or equal to i.

    // Copy A to B, starting from the end of A.
    for (int j = n - 1; j >= 0; j--)
    {
        *(sorted + *(temp + *(array + j)) - 1) = *(array + j); // B[C[A[j]] - 1] = A[j]
        *(temp + *(array + j)) -= 1;                           // C[A[j]] = C[A[j]] - 1
    }

    free(temp);

    return sorted; // Return sorted array B[0 : n - 1]
}