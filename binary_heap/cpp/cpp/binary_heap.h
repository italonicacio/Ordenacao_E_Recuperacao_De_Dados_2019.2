#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <string>

#include "vertex.h"

// class Graph;
class BinaryHeap
{
    protected:
        
        int size;
        int lenght;
        
    
        void MaxHeapify(int position);
        void MinHeapify(int position);


    public:
        Vertex** array_vertices;
        BinaryHeap(){}
        BinaryHeap(int lenght);
        BinaryHeap(std::string* file_name);
        ~BinaryHeap();
        bool isMaxHeap();
        bool isMinHeap();
    
        void BuildMaxHeap();
        void BuildMinHeap();

        Vertex* ExtractMax();
        Vertex* ExtractMin();

        void IncreaseKey(int position, int key);
        void DecreaseKey(int position, int key);

        void MaxInsert(int key);
        void MinInsert(int key);

        void Heapsort();

        void DefaultArray();

    
        friend std::ostream& operator<<(std::ostream &os, const BinaryHeap* binary_heap);

        inline int Parent(int position) { return (position - 1)/2; }

        inline int Left(int position) { return position*2+1; }

        inline int Right(int position) { return position*2+2; }
        
        inline int GetLenght() { return this->lenght; }

        inline int Maximum() { return this->array_vertices[0]->GetValue(); }

        inline int Minimum() { return this->array_vertices[0]->GetValue(); }

        
        
};

std::ostream& operator<<(std::ostream &os, const BinaryHeap* binary_heap);



#endif