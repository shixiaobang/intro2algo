#include "merge_sort.h"
#include <math.h>

/*
This procedure is the rare case that uses both 1-origin indexing (for array A) and 0-origin
indexing (for arrays L and R). Using 0-origin indexing for L and R makes for a simpler loop
invariant in Exercise 2.3-3.
*/

int merge(int *array, int p, int q, int r)
{
    int n_left = q - p + 1; // length of A[p : q]
    int n_right = r - q;    // length of A[q + 1 : r]

    // Let L[0 : nL – 1] and R[0 : nR – 1] be new arrays
    int left[n_left];
    int right[n_right];

    // copy A[p : q] into L[0 : nL – 1]
    for (int i = 0; i < n_left; i++)
    {
        *(left + i) = *(array + p + i);
    }
    // copy A[q + 1 : r] into R[0 : nR – 1]
    for (int j = 0; j < n_right; j++)
    {
        *(right + j) = *(array + q + j + 1);
    }

    int i = 0; // i indexes the smallest remaining element in L
    int j = 0; // j indexes the smallest remaining element in R
    int k = p; // k indexes the location in A to fill

    // As long as each of the arrays L and R contains an unmerged element,
    // copy the smallest unmerged element back into A[p : r].
    while (i < n_left && j < n_right)
    {
        if (*(left + i) < *(right + j))
        {
            *(array + k) = *(left + i);
            i++;
        }
        else
        {
            *(array + k) = *(right + j);
            j++;
        }
        k++;
    }

    // Having gone through one of L and R entirely, copy the
    // remainder of the other to the end of A[p : r].
    while (i < n_left)
    {
        *(array + k) = *(left + i);
        i++;
        k++;
    }
    while (j < n_right)
    {
        *(array + k) = *(right + j);
        j++;
        k++;
    }

    return 0;
}

int merge_sort(int *array, int p, int r)
{
    if (p >= r) // zero or one element?
    {
        return 1;
    }
    else
    {
        int q = (int)floor((p + r) / 2); // midpoint of A[p : r]

        merge_sort(array, p, q);     // recursively sort A[p : q]
        merge_sort(array, q + 1, r); // recursively sort A[q + 1 : r]

        // Merge A[p : q] and A[q + 1 : r] into A[p : r].
        merge(array, p, q, r);

        return 0;
    }
}