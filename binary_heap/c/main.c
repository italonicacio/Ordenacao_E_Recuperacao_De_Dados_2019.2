#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDEBUG

//#define LENGHT_HEAP 10

int main(int argc, char *argv[])
{  
    FILE *file = NULL;
    struct BinaryHeap binaryheap;
    int lenght;

    char folder[80] = "instancias-num/";
    
    if(argc == 1)
    {
        file = fopen("instancias-num/num.1000.1.in", "r");
        if(file == NULL)
        {
            puts("Erro ao ler o arquivo");
            exit(1);
        }
    }else{
        strcat(folder, argv[1]);
        file = fopen(folder, "r");
        if(file == NULL)
        {
            puts("Erro ao ler o arquivo");
            exit(1);
        }
    }



    fscanf(file, "%d", &lenght);
    InitBinaryHeap(&binaryheap, lenght);
  
    for(int i = 0; i < binaryheap.lenght; i++)
    {

        fscanf(file, "%d", &binaryheap.array[i] );
        #ifdef DEBUG
            printf("array[%d] = %d\n", binaryheap.size, binaryheap.array[binaryheap.size]);
            printf("size = %d\n", binaryheap.size);
        #endif

        binaryheap.size++;
    }
    
       
    #ifndef DEBUG
        PrintBinaryHeap(&binaryheap);
    
        Heapsort(&binaryheap);
    
        PrintBinaryHeap(&binaryheap);
    #endif


    fclose(file);
    EndBinaryHeap(&binaryheap);
    
    return 0;
}