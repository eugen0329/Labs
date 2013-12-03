#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template < class type1 > class Node;
template < class type1 >
ostream& operator<< (ostream&, const Node<type1>&);

template <class type1> class Node {
public:
    Node(type1, int);
    Node();
    Node(const Node<type1>&);
    ~Node();
    
    int keyAreExists(int);
    long getSumOfTheKeys();
    int add(type1, int);
    type1 findElementWithKey(int);
    Node operator= (Node*);
    Node operator+= (Node*);
    friend ostream& operator<< <> (ostream&, const Node<type1>&);
    
    bool isEmptyNode;
private:
    type1 object;
    int key;
    Node *left;
    Node *right;
};

template < class type1 > 
    long Node<type1>::getSumOfTheKeys()
{
    long sum = 0;
    
    if (left) sum += left->getSumOfTheKeys();
    if (right) sum += right->getSumOfTheKeys();
    sum += this->key;

    return sum;
}

template<class type1> 
    type1 Node<type1>::findElementWithKey(int inputKey)
{
    Node<type1> *pointer;

    if(this->key == inputKey) {
        return this->object;
    } 
    
    pointer = this;
    while (pointer->key != inputKey) {
        if (inputKey < pointer->key) {
            if(pointer->left) {
                pointer = pointer->left;
            } else {
                cout << "There is  no such elem" << endl;
                exit(1);
            }   
        } else if (inputKey > pointer->key) {
            if(pointer->right) {
                pointer = pointer->right;
            } else {
                cout << "There is  no such elem" << endl;
                exit(1);
            }
        } else {
            break;
        }
    }
    
    return pointer->object;
}

template<class type1> 
    Node<type1>::Node(type1 inputObject, int key)
{
    this->object = inputObject;
    this->key = key;
    left = NULL;
    right = NULL;
}

template<class type1> 
    Node<type1>::Node()
{
    isEmptyNode = true;
    this->key = 0;
    left = NULL;
    right = NULL;
}

template<class type1> 
    Node<type1>::Node(const Node<type1>& node2)
{
    isEmptyNode = false;
    this->object = node2.object;
    this->key = node2.key;
    this->left = node2.left;
    this->right = node2.right;
}

template < class type1 >
    int Node<type1>::add(type1 inputObject, int inputKey)
{
    Node *pointer;
    
    if(isEmptyNode) {
        this->object = inputObject;
        this->key = inputKey;
        isEmptyNode = false;
        return 0;
    }

    pointer = this;
    while (true) {
        if (inputKey < pointer->key) {
            if(pointer->left) {
                pointer = pointer->left;
            } else {
                pointer->left = new Node(inputObject, inputKey);
                break;
            }   
        } else {
            if(pointer->right) {
                pointer = pointer->right;
            } else {
                pointer->right = new Node(inputObject, inputKey);
                break;
            }
        }
    }

    return 0;
}

template <class type1> 
    Node<type1>::~Node()
{
    if (this->left != NULL) {
        delete this->left;
    }
    if (this->right != NULL) {
        delete this->right;
    }
}

template < class type1 >
    ostream& operator<< (ostream& out, const Node<type1>& inputNode)
{
    if(inputNode.left) {
        out << *inputNode.left;
    }
    out << inputNode.object << endl;
    if(inputNode.right) {
        out << *inputNode.right;
    }
    return out;
}

template<class type1>
    Node<type1> Node<type1>::operator= (Node* obj2)
{
    this->object = obj2.object;
    this->key = obj2.key;

    if (obj2.left) {
        if (left) {
            left = *obj2.left;
        }
    } else if (left) {
        delete left;
    }

    if (obj2.right) {
        if (right) {
            right = *obj2.right;
        }
    } else if (left) {
        delete left;
    }
    
    return *this;
}

template<class type1>
    int Node<type1>::keyAreExists(int inputKey)
{

    Node *pointer;

    pointer = this;
    while (pointer->key != inputKey) {
        if (inputKey < pointer->key) {
            if(pointer->left) {
                pointer = pointer->left;
            } else {
                
                return 1;
            }   
        } else if (inputKey > pointer->key) {
            if(pointer->right) {
                pointer = pointer->right;
            } else {
                
                return 1;
            }
        } else {
            break;
        }
    }
    
    return 0;
}

template<class type1>
    Node<type1> Node<type1>::operator+= (Node* obj2)
{
    Node<type1>* pointer;

    pointer = this;
    while (true) {
        if (obj2->key < pointer->key) {
            if(pointer->left) {
                pointer = pointer->left;
            } else {
                pointer->left = new Node;
                pointer->left = *obj2;
                break;
            }   
        } else {
            if(pointer->right) {
                pointer = pointer->right;
            } else {
                pointer->right = new Node;
                pointer->right = *obj2;
                break;
            }
        }
    }

    return *this;
}

#endif
