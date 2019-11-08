#include "binary_heap.h"
#include <fstream>
#include <string>
#include <cstdio>

BinaryHeap::BinaryHeap(int lenght): lenght(lenght), size(0)
{
    this->array = new int[this->lenght];
    for(int i = lenght; i > 0; i-- )
        this->array[this->lenght - i] = i;
}

BinaryHeap::BinaryHeap(std::string* file_name): size(0)
{
    FILE *file = nullptr;

    
    
    file = fopen(file_name->c_str(), "r");

    if(file == NULL)
    {
        std::cerr << "Erro ao abrir arquivo" << std::endl;
        exit(1);
    }
    
    fscanf(file, "%d", &this->lenght);

    this->array = new int[this->lenght];
    
    for(int i = 0; i < this->lenght; i++)
    {
        fscanf(file, "%d", &this->array[i]);
    }
        
    
    std::clog << this->lenght<< std::endl;
    
    fclose(file);
    
}

BinaryHeap::~BinaryHeap()
{
    delete this->array;
}

std::ostream& operator<<(std::ostream &os, const BinaryHeap &binary_heap)
{
    for(int i = 0; i < binary_heap.lenght; i++)
        os << binary_heap.array[i] << " ";
    os << std::endl;
    return os;
}

//int BinaryHeap::isMaxHeap()

void BinaryHeap::MaxHeapify(int position)
{
    int left = Left(position);
    int right = Right(position);

    int bigger;

    if((left <= this->size-1) && (this->array[left] > this->array[position]) )
        bigger = left;
    else
        bigger = position;
    if( (right <= this->size-1) && (this->array[right] > this->array[bigger]) )
        bigger = right;
    if(bigger != position)
    {
        int aux = this->array[position];
        this->array[position] = this->array[bigger];
        this->array[bigger] = aux;
        MaxHeapify(bigger);
    }


    
}


void BinaryHeap::BuildMaxHeap()
{
    this->size = this->lenght;
    for(int i = (this->lenght-1)/2; i>=0; i--)
        MaxHeapify(i);

}

void BinaryHeap::Heapsort()
{
    BuildMaxHeap();

    for(int i = this->lenght-1; i > 0; i --)
    {
        int aux = this->array[0];
        this->array[0] = this->array[i];
        this->array[i] = aux;
        this->size --;
        MaxHeapify(0);
    }

}