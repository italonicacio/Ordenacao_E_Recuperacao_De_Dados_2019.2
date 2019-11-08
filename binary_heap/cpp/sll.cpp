#include "sll.h"

SLL::SLL(): head(nullptr), tail(nullptr), size(0)
{
}

SLL::SLL(Vertex* vertex): head(vertex), tail(vertex), size(1)
{
}

SLL::~SLL()
{

    while()
    {
        /* code */
    }
    
}

void SLL::Append(int value)
{
    Vertex* new_vertex = nullptr;
    new_vertex = new Vertex(value);

    if(new_tail == nullptr)

}


std::ostream& operator<<(std::ostream &os, const SLL* sll)
{
    //for(int i = 0; i < this->size; i++);
    return os;
}