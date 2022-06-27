#include "heap_sort.h"
#include "../binary_heap/binary_heap.h"

int heapsort(int *array, int n)
{
    build_max_heap(array, n);

    int heap_size = n;

    for (int i = n - 1; i >= 1; i--)
    {
        int temp = *(array);
        *(array) = *(array + i); // exchange A[0] with A[i]
        *(array + i) = temp;
        heap_size--;
        max_heapify(array, heap_size, 0);
    }

    return 0;
}
