#ifndef SLL_H
#define SLL_H
#include <iostream>
#include "vertex.h"

struct Node
{

    Vertex* vertex;
    Node* next_node;

};

class SLL
{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        SLL();
        SLL(Vertex* vertex);
        ~SLL();
        void Append(int value);
        friend std::ostream& operator<<(std::ostream &os, const SLL* sll);

    
};

std::ostream& operator<<(std::ostream &os, const SLL* sll);

#endif