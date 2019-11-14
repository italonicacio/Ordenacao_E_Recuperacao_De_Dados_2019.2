#include "binary_heap.h"
#include <fstream>
#include <string>
#include <cstdio>

BinaryHeap::BinaryHeap(int lenght): lenght(lenght), size(0)
{
    this->array_vertices = new Vertex*[this->lenght];
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

    this->array_vertices = new Vertex*[this->lenght];
    
    for(int i = 0; i < this->lenght; i++)
    {

        int value;
        this->array_vertices[i] = nullptr;

        fscanf(file, "%d", &value);
        this->array_vertices[i] = new Vertex(value);

    }
    
    fclose(file);
    
}

BinaryHeap::~BinaryHeap()
{
    for(int i = 0; i < this->lenght; i++)
    {
        delete this->array_vertices[i];
    }
    delete this->array_vertices;

}

Vertex* BinaryHeap::ExtractMax()
{
    Vertex* max = nullptr;
    if(this->size < 1)
        return max; 
    max = this->array_vertices[0];
    this->size--;
    this->array_vertices[0] = this->array_vertices[this->size];
    MaxHeapify(0);
    return max;

}

Vertex* BinaryHeap::ExtractMin()
{
    Vertex* min = nullptr;
    if(this->size < 1)
        return min;
    min = this->array_vertices[0];
    this->size--;
    this->array_vertices[0] = this->array_vertices[this->size];
    MinHeapify(0);
    return min;
}

void BinaryHeap::IncreaseKey(int position, int key)
{
    if(key < this->array_vertices[position]->GetValue() )
        return;
    this->array_vertices[position]->SetValue(key);

    while (position > 0 && (*this->array_vertices[Parent(position)] < *this->array_vertices[position]))
    {
        Vertex* aux = this->array_vertices[Parent(position)];
        this->array_vertices[Parent(position)] = this->array_vertices[position];
        this->array_vertices[position] = aux;
        position = Parent(position);
        
    }
    
}

void BinaryHeap::DecreaseKey(int position, int key)
{
    if(key > this->array_vertices[position]->GetValue() )
        return;
    this->array_vertices[position]->SetValue(key);

    while (position > 0 && (*this->array_vertices[Parent(position)] > *this->array_vertices[position]))
    {
        Vertex* aux = this->array_vertices[Parent(position)];
        this->array_vertices[Parent(position)] = this->array_vertices[position];
        this->array_vertices[position] = aux;
        position = Parent(position);
        
    }
}

void BinaryHeap::MaxHeapify(int position)
{
    int left = Left(position);
    int right = Right(position);

    int bigger;

    if((left <= this->size-1) && ( *this->array_vertices[left] > *this->array_vertices[position]) )
        bigger = left;
    else
        bigger = position;
    if( (right <= this->size-1) && ( *this->array_vertices[right] > *this->array_vertices[bigger]) )
        bigger = right;

    if(bigger != position)
    {
        Vertex* aux = this->array_vertices[position];
        this->array_vertices[position] = this->array_vertices[bigger];
        this->array_vertices[bigger] = aux;
        MaxHeapify(bigger);
    }
    
}

void BinaryHeap::MinHeapify(int position)
{
    int left = Left(position);
    int right = Right(position);

    int smaller;

    if((left <= this->size-1) && (*this->array_vertices[left] < *this->array_vertices[position]) )
        smaller = left;
    else
        smaller = position;
    if( (right <= this->size-1) && (*this->array_vertices[right] < *this->array_vertices[smaller]) )
        smaller = right;
    if(smaller != position)
    {
        Vertex* aux = this->array_vertices[position];
        this->array_vertices[position] = this->array_vertices[smaller];
        this->array_vertices[smaller] = aux;
        MinHeapify(smaller);
    }

}



void BinaryHeap::BuildMaxHeap()
{
    this->size = this->lenght;
    for(int i = (this->lenght-1)/2; i>=0; i--)
        this->MaxHeapify(i);

}

void BinaryHeap::BuildMinHeap()
{
    this->size = this->lenght;
    for(int i = (this->lenght-1)/2; i>=0; i--)
        this->MinHeapify(i);
    
}


void BinaryHeap::Heapsort()
{
    BuildMaxHeap();

    for(int i = this->lenght-1; i > 0; i --)
    {
        Vertex* aux = this->array_vertices[0];
        this->array_vertices[0] = this->array_vertices[i];
        this->array_vertices[i] = aux;
        this->size --;
        MaxHeapify(0);
    }

}

void BinaryHeap::DefaultArray()
{
    for(int i = this->lenght; i > 0; i-- )
    {
        Vertex* new_vertex = new Vertex(i);
        this->array_vertices[this->lenght - i] = new_vertex;
    }
}

std::ostream& operator<<(std::ostream &os, const BinaryHeap* binary_heap)
{
    
    for(int i = 0; i < binary_heap->lenght; i++)
        os << binary_heap->array_vertices[i]->GetValue() << " ";
    os << std::endl;
    return os;
}