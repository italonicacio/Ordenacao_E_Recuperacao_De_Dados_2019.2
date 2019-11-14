#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <climits>

#include "sll.h"


class BinaryHeap;
class Graph
{

    private:
        int n;
        Vertex** adjacency_matrix;
        SLL* adjacency_list;
        //BinaryHeap* binary_heap;

        void InitializeSingleSource(int initial_vertex);
        void Relax(int vertex_u, int vertex_v); 

    public:
        BinaryHeap* binary_heap;
        Graph(): binary_heap(nullptr) {}
        Graph(std::string* file_name);
        ~Graph();

       void Dijkstra(int initial_vertex);
        
};

#endif