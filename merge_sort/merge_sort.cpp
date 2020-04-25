#include <iostream>
#include <cmath>


#define SIZE 50
#define INIT 0

void Swap(int* array, int pos1, int pos2)
{
    int aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

void Merge(int* array, int init,int middle, int end)
{   
    int i = init;
    int j = middle +1;
    int k = 0;
    int* aux_array =  nullptr;
    aux_array = new int[(end - init+1)];

    while(i <= middle && j <= end)
    {
        if(array[i] < array[j])
        {
            aux_array[k] = array[i];
            i++;
        }else{
            aux_array[k] = array[j];
            j++;
        }
        k++; 
    }

    while (i <= middle)
    {
        aux_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        aux_array[k] = array[j];
        j++;
        k++;
    }

    for(int c = init; c <= end; c++)
        array[c] = aux_array[c - init];
    
    delete aux_array;

}


void MergeSort(int* array, int init, int end)
{
    int middle;

    if( init < end)
    {
        middle = (end+init)/2;
        MergeSort(array, init, middle);
        MergeSort(array, middle+1, end);
        Merge(array,init, middle, end);
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

    MergeSort(array, INIT, SIZE);

    std::cout << "Array ordenado: " << std::endl;
    for(int i = 0; i<SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;

    return 0;
}