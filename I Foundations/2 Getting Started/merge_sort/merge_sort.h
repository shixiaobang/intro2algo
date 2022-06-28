#if !defined(MERGE_SORT_H)
#define MERGE_SORT_H

// Merge the two sorted subarrays A[p : q] and A[q + 1 : r] back into A[p : r]
int merge(int *array, int p, int q, int r);

// Mergesort array A[p : r]
int merge_sort(int *array, int p, int r);

#endif // MERGE_SORT_H
