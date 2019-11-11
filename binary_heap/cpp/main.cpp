#include <string>

#include "binary_heap.h"
#include "sll.h"
#include "graph.h"

#define LENGHT 10

int main(int argc, char* argv[])
{
    //std::string dir("instancias-num/");
    //dir = dir + argv[1];

    //BinaryHeap heap(&dir);
    Vertex vertex(10);

    SLL* sll = new SLL(&vertex);

    std::cout << sll;


    
    
    
    //heap.Heapsort();
    //std::cout << heap;

    return 0;
}