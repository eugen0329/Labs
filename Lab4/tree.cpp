#include "tree.hpp"

template <class type1, class type2>
Node<type1, type2>::Node(type1 inputObject, type2 key)
{
    this->object = inputObject;
    this->key = key;
    left = NULL;
    right = NULL;
}

template <class type1, class type2>
Node<type1, type2> Node<type1, type2>::add(type1 someClass, type2 inputKey)
{
    int i;
    type1* pointer;

    pointer = this->object;
    while(true) {
        if(pointer->key < inputKey ) {
            if(pointer->left != NULL) {
                pointer = pointer->left;      
            } else {
                pointer->left = new Node(someClass);
                pointer = pointer->left;
                break;
            }
        } else {
            if (pointer->right != NULL) {
                pointer = pointer->right; 
            } else {
                pointer->right = new Node(someClass);
                pointer = pointer->right;
                break;
            }
        }
    }
     
    pointer->key = inputKey;
    
    return *this;
}

template <class type1, class type2>
Node<type1, type2>::~Node()
{
    if( this->left != NULL) {
        delete this->left;
    }
    if(this->right != NULL) {
        delete this->right;
    }
    delete object;
}
