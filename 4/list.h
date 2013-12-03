#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template < class type1 > class List;
template < class type1 >
ostream& operator<< (ostream&, const List<type1>&);

template <class type1> class List {
public:
    void add(
    friend ostream& operator<< <> (ostream&, const List<type1>&);
    
private:
};


template<class type1> 
    List<type1>::List(type1 inputObject, int key)
{
    this->object = inputObject;
    this->key = key;
    left = NULL;
    right = NULL;
}

template<class type1> 
    List<type1>::List()
{
    isEmptyList = true;
    this->key = 0;
    left = NULL;
    right = NULL;
}

template<class type1> 
    List<type1>::List(const List<type1>& List2)
{
    isEmptyList = false;
    this->object = List2.object;
    this->key = List2.key;
    this->left = List2.left;
    this->right = List2.right;
}

template <class type1> 
    List<type1>::~List()
{
    if (this->left != NULL) {
        delete this->left;
    }
    if (this->right != NULL) {
        delete this->right;
    }
}

template < class type1 >
    ostream& operator<< (ostream& out, const List<type1>& inputList)
{
    if(inputList.left) {
        out << *inputList.left;
    }
    out << inputList.object << endl;
    if(inputList.right) {
        out << *inputList.right;
    }
    return out;
}

#endif
