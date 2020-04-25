#include <iostream>
#include <cmath>


#define SIZE 50

void SelectionSort(int* array)
{
    for(int i = 0; i < SIZE; i++)
    {       
        int aux = array[i];
        int smaller = i;
        for(int j = i; j < SIZE; j++)
        {
            if( array[j] < array[smaller])
                smaller = j;
            
        }
        array[i] = array[smaller];
        array[smaller] = aux;
    }
}


int main()
{
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % SIZE;
    }

    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    SelectionSort(array);
    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;

    return 0;
    
}