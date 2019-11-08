#ifndef GRAPH_H
#define GRAPH_H

#include "sll.h"


class Graph
{
    public:
        int** adjacency_matrix;
        SLL* adjacency_list;

    private:
        Graph();
        ~Graph();

};

#endif