#include <string>

#include "binary_heap.h"
#include "graph.h"

#define LENGHT 10

int main(int argc, char* argv[])
{
    std::string dir("instancias-num/");
    dir = dir + argv[1];

    BinaryHeap heap(&dir);
    
    
    
    heap.Heapsort();
    std::cout << heap;

    return 0;
}