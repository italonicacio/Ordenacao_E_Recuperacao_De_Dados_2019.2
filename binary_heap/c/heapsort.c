#include "heapsort.h"

void Heapsort(struct BinaryHeap* binaryheap)
{
    BuildMaxHeap(binaryheap);
    
    for(int i = binaryheap->lenght-1; i > 0; i--)
    {
        int aux = binaryheap->array[0];
        binaryheap->array[0] = binaryheap->array[i];
        binaryheap->array[i] = aux;
        binaryheap->size --;
        MaxHeapify(binaryheap, 0);
    }

}