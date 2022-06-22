#include "insertion_sort.h"

int insertion_sort(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = *(array + i);
        // Insert A[i] into the sorted subarray A[0 : i – 1].
        int j = i - 1;
        while (j > -1 && *(array + j) > key)
        {
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = key;
    }

    return 0;
}