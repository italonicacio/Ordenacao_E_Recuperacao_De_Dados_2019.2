#include <iostream>
#include <cmath>


#define SIZE 50

int* InsertionSort(int* array)
{
    int* aux_array = new int[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        aux_array[i] = array[i];
        int j = i - 1;
        int key = aux_array[i];
        while(j >= 0 && key < aux_array[j])
        {
            aux_array[j+1] = aux_array[j];
            j--;
        }
            
        aux_array[j+1] = key;
    }
    return aux_array;
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

    int *int_array = InsertionSort(array);
    for(int i = 0; i<SIZE; i++)
        std::cout << int_array[i] << " ";

    std::cout << std::endl;
    return 0;
}