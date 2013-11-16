#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

class SomeClass {
public:
    int key;
    int number;
};


template <class type1, class type2> 
class Node {
public:
    Node(type1, type2);
    void add(type1, type2);
    type2 getKey() { return key;}
    ~Node();
private:
    type1 object;
    type2 key;
    Node* left;
    Node* right;
};

#endif
