#include <limits.h>
#include "max_priority_queue.h"
#include "../binary_heap/binary_heap.h"

int max_heap_maximum(int *array, int heap_size)
{
    if (heap_size < 1)
    {
        return -1;
    }
    else
    {
        return *(array);
    }
}

int max_heap_extract_max(int *array, int *heap_size_ptr)
{
    int max = max_heap_maximum(array, *(heap_size_ptr));

    *(array) = *(array + *(heap_size_ptr)-1);

    *(heap_size_ptr) -= 1;

    max_heapify(array, *(heap_size_ptr), 0);

    return max;
}

int max_heap_increase_key(int *array, int x, int k)
{
    if (k < *(array + x))
    {
        return -1;
    }
    else
    {
        *(array + x) = k;
        // find the index i in array A where A[x] = k occurs
        int i = x;
        while (i >= 0 && *(array + parent(i)) < *(array + i))
        {
            // updating the information that maps priority queue objects to array indices
            int temp = *(array + i);
            *(array + i) = *(array + parent(i)); // exchange A[i] with A[PARENT(i)]
            *(array + parent(i)) = temp;

            i = parent(i);
        }
    }
}

int max_heap_insert(int *array, int n, int *heap_size_ptr, int k)
{
    int x = *(heap_size_ptr);

    if (*(heap_size_ptr) == n)
    {
        return -1;
    }
    else
    {
        *(heap_size_ptr) += 1;

        *(array + x) = INT_MIN;

        // map x to index heap-size in the array
        max_heap_increase_key(array, x, k);

        return 0;
    }
}