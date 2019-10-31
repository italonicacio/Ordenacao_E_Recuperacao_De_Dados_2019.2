#ifndef HEAP_H
#define HEAP_H

struct BinaryHeap
{
    int *array;
    int size;
    int lenght;
};

void InitBinaryHeap(struct BinaryHeap *binaryheap, int lenght_heap);

void EndBinaryHeap(struct BinaryHeap *binaryheap);

void PrintBinaryHeap(struct BinaryHeap *binaryheap);

int Parent(int position);

int Left(int position);

int Right(int position);


#endif