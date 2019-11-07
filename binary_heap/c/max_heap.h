#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "binary_heap.h"

int isMaxHeap();

void MaxHeapify(struct BinaryHeap* binaryheap, int position);

void BuildMaxHeap(struct BinaryHeap* binaryheap);

#endif