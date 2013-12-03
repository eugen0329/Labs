#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template < class type1 > class Queue;
template < class type1 >
ostream& operator<< (ostream&, const Queue<type1>&);

template <class type1> class Queue {
public:
    Queue(type1);
    Queue();
    void add(type1);
    friend ostream& operator<< <> (ostream&, const Queue<type1>&);
    void del() 
private:
    type1 object;
    Queue *next;
    Queue *last;
    Queue *first;
};

template<class type1>
    Queue<type1>::add(type1 inputObject)
{
    this->object = inputObject;

    if(first == NULL) {
        first = this;
    }
    
    if(last) {
        last->next = this;
    }
    
    last = this; 
    next = NULL;
}

template<class type1> 
    Queue<type1>::Queue()
{
    first = NULL;
    last = NULL;
    next = NULL; 
}

template<class type1> 
    Queue<type1>::Queue(const Queue<type1>& Queue2)
{
}

template <class type1> 
    Queue<type1>::~Queue()
{
}

template < class type1 >
    ostream& operator<< (ostream& out, const Queue<type1>& inputQueue)
{
    if(inputQueue.last) {
        out << *inputQueue.last;
    }
    out << inputQueue.object << endl;
    if(inputQueue.next) {
        out << *inputQueue.next;
    }
    return out;
}

#endif
