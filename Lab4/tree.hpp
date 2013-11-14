#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <class type1, class type2> 
class Node {
public:
    Node(type1, type2);
    Node add(type1, type2);

    ~Node();
private:
    //inline void findNode(type1);
    type2 key;
    type1* object;
    type1* left;
    type1* right;
};

#endif
