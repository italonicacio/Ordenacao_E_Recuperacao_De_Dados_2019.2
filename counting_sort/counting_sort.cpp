#include <iostream>
#include <stdio.h>
#include <cmath>


#define SIZE 20

void PrintArray(int* array, int size)
{
    
    for(int i = 0; i<size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

}


void CountingSort(int* array, int size)
{
    int max;
    int* cont;
    int* aux_array = new int[size];
    max = array[0];

    for(int i = 1; i < size; i++)
        if(max < array[i])
            max = array[i];
    cont = new int[max + 1];
    
    for(int i = size-1; i >= 0; i--)
        cont[array[i]]++;

    for(int i = 1; i <= max; i++)
        cont[i] = cont[i] + cont[i-1];

    for(int i = size-1; i >= 0; i--)
        aux_array[ --cont[array[i]] ] = array[i];
        
    for(int i = 0; i < size; i++)
        array[i] =  aux_array[i];
    
}


int main()
{
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % SIZE;
    }

    std::cout << "Array não ordenado: " << std::endl;
    PrintArray(array, SIZE);

    CountingSort(array, SIZE);

    std::cout << "Array ordenado: " << std::endl;
    PrintArray(array, SIZE);

    return 0;
}