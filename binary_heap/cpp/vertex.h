#ifndef VERTEX_H
#define VERTEX_H




class Vertex
{
    private:
        int value;
        int parent;
        int id_heap;

    public:
        Vertex(){}
        Vertex(int value): value(value){}
        void SetValue(int value){ this->value = value; }
        void SetParent(int parent){ this->parent = parent; }
        void SetIdHeap(int id_heap){ this->id_heap = id_heap; }
        int GetValue(){ return this->value; }
        int GetParent(){ return this->parent; }
        int GetIdHeap(){ return this->id_heap; }

};

#endif