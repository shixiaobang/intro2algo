#if !defined(BINARY_HEAP_H)
#define BINARY_HEAP_H

// Parent of A[i]
int parent(int i);

// Left child of A[i]
int left(int i);

// Right child of A[i]
int right(int i);

// Maintain the max-heap property of A[i]
int max_heapify(int *array, int heap_size, int i);

// Produce a max-heap from an unordered input array A[0 : n - 1]
int build_max_heap(int *array, int n);

#endif // BINARY_HEAP_H
