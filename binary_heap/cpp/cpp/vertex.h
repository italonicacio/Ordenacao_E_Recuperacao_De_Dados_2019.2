#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>


class Vertex
{
    private:
        int value;
        int parent;
        int id_heap;

    public:
        Vertex(){}
        Vertex(int value): value(value){}
        inline void SetValue(int value){ this->value = value; }
        inline void SetParent(int parent){ this->parent = parent; }
        inline void SetIdHeap(int id_heap){ this->id_heap = id_heap; }
        inline int GetValue(){ return this->value; }
        inline int GetParent(){ return this->parent; }
        inline int GetIdHeap(){ return this->id_heap; }

        inline bool operator>(const Vertex& vertex)
        {

            if(this->value > vertex.value )
                return true;
            else
                return false;
        }

        inline bool operator<(const Vertex& vertex)
        {
            
            if(this->value < vertex.value)
                return true;
            else
                return false;
        }
        

};





#endif