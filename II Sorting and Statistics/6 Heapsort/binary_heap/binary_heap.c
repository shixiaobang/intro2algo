#include "binary_heap.h"
#include <math.h>

int parent(int i) { return (int)floor((i - 1) / 2); }

int left(int i) { return 2 * i + 1; }

int right(int i) { return 2 * i + 2; }

int max_heapify(int *array, int heap_size, int i)
{
    int l = left(i);
    int r = right(i);

    int largest;

    if (l <= heap_size - 1 && *(array + l) > *(array + i))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= heap_size - 1 && *(array + r) > *(array + largest))
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = *(array + i);
        *(array + i) = *(array + largest); // exchange A[i] with A[largest]
        *(array + largest) = temp;

        max_heapify(array, heap_size, largest);
    }

    return 0;
}
