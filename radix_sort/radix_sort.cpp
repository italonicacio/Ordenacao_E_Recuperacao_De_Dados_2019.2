#include <iostream>
#include <stdio.h>
#include <cmath>


#define SIZE 50

void PrintArray(int* array, int size)
{
    
    for(int i = 0; i<size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

}


void RadixSort(int* array, int size)
{
    int max = array[0];
    int* aux_array = new int[size];
    int exp;

    for(int i = 1; i < size; i++)
        if(max < array[i])
            max = array[i];
    
    for(int exp = 1; max/exp > 0; exp*=10)
    {
        
        int cont[10] = {0};

        for(int i = size-1; i >= 0; i--)
            cont[ ( array[i]/exp ) % 10 ]++;

        for(int i = 1; i < 10; i++)
            cont[i] = cont[i] + cont[i-1];

        for(int i = size-1; i >= 0; i--)
            aux_array[ --cont[(array[i]/exp)%10] ] = array[i];
        
        for(int i = 0; i < size; i++)
            array[i] =  aux_array[i];
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
    PrintArray(array, SIZE);

    RadixSort(array, SIZE);

    std::cout << "Array ordenado: " << std::endl;
    PrintArray(array, SIZE);

    return 0;
}