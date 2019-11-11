#include "sll.h"

SLL::SLL(): head(nullptr), tail(nullptr), size(0)
{
}

SLL::SLL(Vertex* vertex): size(1)
{

    Node* new_node = nullptr;
    new_node->vertex = vertex;
    this->head = new_node;
    this->tail = new_node;

}

SLL::~SLL()
{
    Node* aux_dell = nullptr;
    aux_dell = this->head;
    
    while(this->head == nullptr)
    {
        delete(this->head->vertex);
        aux_dell = this->head->next_node;
        delete(this->head);
        this->head = aux_dell;
        
    }
    
}

void SLL::Append(int value)
{
    Node* new_node = nullptr;
    new_node = new Node();
    new_node->next_node = nullptr;
    new_node->vertex = new Vertex(value);

    if(this->tail == nullptr)
    {
        this->tail = new_node;
        this->head = new_node;
    }else{
        this->tail->next_node = new_node;
        this->tail = new_node;
    }
    this->size++;
}


std::ostream& operator<<(std::ostream &os, const SLL* sll)
{
    Node* aux_node = nullptr;
    aux_node = sll->head;

    while(aux_node != nullptr)
    {
        os << aux_node->vertex->GetValue() << " "; 
        aux_node = aux_node->next_node; 
    }
    os<<std::endl;
    

    return os;
}