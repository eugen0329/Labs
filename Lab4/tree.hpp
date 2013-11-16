#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <class type1, class type2> 
class Node {
public:
    explicit Node(type1, type2);
    void add(type1, type2);

    ~Node();
private:
    type1 object;
    type2 key;
    Node* left;
    Node* right;
};

#endif
