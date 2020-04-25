#include <iostream>
#include <cmath>


#define SIZE 50

void BubbleSort(int* array)
{
    bool change;
    do
    {
        change = false;
        for(int i = 0; i < SIZE - 1; i++)
        {       
            if(array[i] > array[i+1])
            {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                change = true;
            }
        }
    }while(change);
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

    BubbleSort(array);
    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
    return 0;
    
}