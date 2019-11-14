
#include <string>
#include <cstdio>
#include <iostream>

#include "graph.h"
#include "binary_heap.h"
#include "vertex.h"




Graph::Graph(std::string* file_name)
{

    FILE* file = nullptr;
    file = fopen(file_name->c_str() , "r");

    if(file == NULL)
    {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        exit(1);
    }

    fscanf(file, "%d", &this->n);

    this->adjacency_matrix = new Vertex*[this->n];
    this->adjacency_list = new SLL[this->n];

    for(int i = 0; i < this->n;i++)
        this->adjacency_matrix[i] = new Vertex[this->n];
    
    for(int i = 0; i < this->n; i++)
    {
        for(int j= i+1; j < this->n; j++)
        {
            int value;
            fscanf(file, "%d", &value);
            this->adjacency_matrix[i][j].SetValue(value);
            this->adjacency_matrix[j][i].SetValue(value);
            
            if(this->adjacency_matrix[i][j].GetValue() !=0)
            {
                this->adjacency_list[i].Append(j);
                this->adjacency_list[j].Append(i);
            }         

        }

    }

    this->binary_heap = new BinaryHeap(this->n);
    
    fclose(file);

}


Graph::~Graph()
{

}



void Graph::InitializeSingleSource(int initial_vertex)
{
    for(int i=0; i< this->n; i++)
    {
        this->binary_heap->array_vertices[i]->SetValue(INT_MAX);
        this->binary_heap->array_vertices[i]->SetParent(NULL);
    }
    this->binary_heap->array_vertices
}
//void Relax(int vertex_u, int vertex_v); 
// void Dijkstra(int initial_vertex);