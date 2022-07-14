#if !defined(QUICKSORT_H)
#define QUICKSORT_H

/**
 * Quicksort the array A[p : r]
 * @param array pointer to array
 * @param p first index of array
 * @param r last  index of array
 */
int quicksort(int *array, int p, int r);

/**
 * Partition the array A[p : r] into two (possibly empty) subarrays A[p : q – 1] (the low side) and A[q + 1 : r] (the high side)
 * @param array pointer to array
 * @param p first index of array
 * @param r last  index of array
 */
int partition(int *array, int p, int r);

#endif // QUICKSORT_H
