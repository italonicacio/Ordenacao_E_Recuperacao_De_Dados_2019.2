#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <string>



class BinaryHeap
{
    protected:
        int* array;
        int size;
        int lenght;
        
        void MaxHeapify(int position);

    public:
        BinaryHeap(int lenght);
        BinaryHeap(std::string* file_name);
        ~BinaryHeap();

    
    friend std::ostream& operator<<(std::ostream &os, const BinaryHeap &binary_heap);

    inline int Parent(int position)
    {
        return (position - 1)/2;
    }

    inline int Left(int position)
    {
        return position*2+1;
    }

    inline int Right(int position)
    {
        return position*2+2;
    }

    int isMaxHeap();
    
    void BuildMaxHeap();

    void Heapsort();
};

std::ostream& operator<<(std::ostream &os, const BinaryHeap &binary_heap);



#endif