#include <iostream>
#include <cmath>


#define SIZE 20
#define INIT 0

void Swap(int* array, int pos1, int pos2)
{
    int aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

int partition(int* array, int init, int end)
{   
    int pivot = end -1;
    int marked = init-1;
    for(int i = init; i < end; i++)
    {
        if(array[i] <= array[pivot]) 
        {
            ++marked;   
            Swap(array, i, marked);  
        }
    }
    return marked;
}


void QuickSort(int* array, int init, int end)
{
    int pos;

    if( init < end)
    {
        pos = partition(array, init, end);
        QuickSort(array, init, pos);
        QuickSort(array, pos+1, end);
    }

}


int main()
{
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % SIZE;
    }

    std::cout << "Array não ordenado: " << std::endl;
    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    QuickSort(array, INIT, SIZE);

    std::cout << "Array ordenado: " << std::endl;
    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;

    return 0;
}