#include "max_heap.h"
#include <stdio.h>
//int isMaxHeap()

void MaxHeapify(struct BinaryHeap* binaryheap, int position)
{
    int left = Left(position);
    int right = Right(position);

    int bigger;

    if((left <= binaryheap->size-1) && (binaryheap->array[left] > binaryheap->array[position]) )
        bigger = left;
    else
        bigger = position;
    if( (right <= binaryheap->size-1) && (binaryheap->array[right] > binaryheap->array[bigger]) )
        bigger = right;
    if(bigger != position)
    {
        int aux = binaryheap->array[position];
        binaryheap->array[position] = binaryheap->array[bigger];
        binaryheap->array[bigger] = aux;
        MaxHeapify(binaryheap, bigger);
    }

   


}

void BuildMaxHeap(struct BinaryHeap* binaryheap)
{
    binaryheap->size = binaryheap->lenght;
    for(int i = (binaryheap->lenght-1)/2; i>=0; i--)
        MaxHeapify(binaryheap, i);
}