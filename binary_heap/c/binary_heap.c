#include "binary_heap.h"
#include <stdlib.h>
#include <stdio.h>

void InitBinaryHeap(struct BinaryHeap *binaryheap, int lenght_heap)
{
    binaryheap->lenght = lenght_heap;
    binaryheap->size = 0;
    binaryheap->array = (int*)malloc(lenght_heap * sizeof(int));
    
}

void EndBinaryHeap(struct BinaryHeap *binaryheap)
{
    free(binaryheap->array);
}

void PrintBinaryHeap(struct BinaryHeap *binaryheap)
{
    for(int i = 0; i < binaryheap->lenght; i++)
        printf("%i ", binaryheap->array[i]);

    puts("\n");
    printf("size_heap = %i\n", binaryheap->size);
}

int Parent(int position)
{
    return (position-1)/2;
}

int Left(int position)
{
    return position*2+1;
}

int Right(int position)
{
    return position*2+2;
}

