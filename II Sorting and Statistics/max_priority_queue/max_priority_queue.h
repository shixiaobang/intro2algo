/*
    Max Priority Queue
    Author: shixiaobang
    Mail: xiaobang.shi@outlook.com
*/
#if !defined(MAX_PRIORITY_QUEUE_H)
#define MAX_PRIORITY_QUEUE_H

// Return the largest value of A[0 : heap_size - 1]
int max_heap_maximum(int *array, int heap_size);

// Remove and return the largest value of A[0 : heap_size - 1]
int max_heap_extract_max(int *array, int *heap_size_ptr);

// Increases the value of A[x] to the new value k, which is assumed to be at least as large as A[x]'s current value.
int max_heap_increase_key(int *array, int x, int k);

// Insert a new value into the max-heap A[0 : n].
int max_heap_insert(int *array, int n, int *heap_size_ptr, int k);

#endif // MAX_PRIORITY_QUEUE_H
