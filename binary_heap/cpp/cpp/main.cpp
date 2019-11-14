#include <string>

#include "binary_heap.h"
#include "sll.h"
#include "graph.h"

#define LENGHT 10

int main(int argc, char* argv[])
{
    // std::string dir("instancias/");
    // dir = dir + argv[1];

    Graph* graph = nullptr;
    //graph = new Graph(&dir);
    graph = new Graph();
    //BinaryHeap* binary_heap = new BinaryHeap(LENGHT);
    graph->binary_heap = new BinaryHeap(LENGHT);
    graph->binary_heap->DefaultArray();

    std::cout << graph->binary_heap;

    graph->binary_heap->BuildMinHeap();

    //binary_heap->BuildMinHeap();

    // binary_heap->Heapsort();

    std::cout << graph->binary_heap;

    graph->binary_heap->DecreaseKey(9, 0);

    

    std::cout << graph->binary_heap;
   
    // delete graph;
   

    return 0;
}