
#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

template <class T> class Node;
template<class T> ostream& operator<< (ostream&, const Node<T>&);

template <class T> class Node {
public:

    Node(T, int);
    Node();
    Node(const Node<T>&);
    ~Node();
    
    int getKey() { return key; }
    int keyAreExists(int);
    long getSumOfTheKeys();
    int add(T, int);
    T findElementWithKey(int);
    Node<T> operator= (Node<T>*);
    Node<T> operator+= (Node<T>*);
    friend ostream& operator<< <T> (ostream&, const Node<T>&);
    
    int size();
    
    bool isEmptyNode;
    class Iterator {
    public:
        Iterator(); 
        Iterator(const Iterator& otherIter);
        Iterator(Node<T>*, Node<T>*); 
        ~Iterator() {}
        inline T operator * ();
        inline Iterator operator ++();
        inline Iterator operator --();
        inline Iterator operator += (int);
        inline Iterator operator -= (int);
        inline Node<T>::Iterator operator = (const Iterator&);
        inline bool operator < (const Iterator&);
        inline bool operator > (const Iterator&);
        inline bool operator == (const Iterator&);
        inline bool operator != (const Iterator&);
        inline bool operator >= (const Iterator&);
        inline bool operator <= (const Iterator&);
    private:
        Node<T>* prev;
        Node<T>* curr;
    };

    Iterator begin();
    Iterator end();
private:
    int insertNodeInPlaceOfAnother(Node<T>, Node<T>**);
    T object;
    int key;
    Node *parent;
    Node *root;
    Node *left;
    Node *right;
};

// {{{ Node Functions

template < class T > 
    int Node<T>::size()
{
    int counter = 1;
    
    for(Node<T>::Iterator it = this->begin(); it < this->end(); ++it) {
        counter++;
    }

    return counter;
}

template < class T > 
    typename Node<T>::Iterator Node<T>::begin()
{
    Node<T>* pointer;
    
    pointer = this;
    while(true) {
        if(pointer->left) {
            pointer = pointer->left;
        } else {
            break;
        }
   } 

    return Node<T>::Iterator(NULL, pointer);
}

template < class T > 
    typename Node<T>::Iterator Node<T>::end()
{
    Node<T>* curr = root;
    
     while(true) {
         if(curr->right) {
             curr = curr->right;
         } else {
             break;
         }
    } 

    Node<T>* prev = curr;

    if(prev->left == NULL) { 
        while(prev->parent->key >= prev->key) {
            prev = prev->parent;
        } 
        prev = prev->parent;
    } else {
        prev = prev->left;
        while(prev->right) {
            prev = prev->right;
        }
    }

    return Node<T>::Iterator(prev, curr);
}

template < class T > 
    long Node<T>::getSumOfTheKeys()
{
    long sum = 0;
    
    if (left) sum += left->getSumOfTheKeys();
    if (right) sum += right->getSumOfTheKeys();
    sum += this->key;

    return sum;
}

template<class T> 
    T Node<T>::findElementWithKey(int inputKey)
{
    Node<T> *pointer;

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

template<class T> 
    Node<T>::Node(T inputObject, int key)
{
    isEmptyNode = false;
    this->parent = NULL;
    this->root = this;
    this->object = inputObject;
    this->key = key;
    left = NULL;
    right = NULL;
}

template<class T> 
    Node<T>::Node()
{
    isEmptyNode = true;
    this->parent = NULL;
    this->key = 0;
    root = NULL;
    left = NULL;
    right = NULL;
}

template<class T> 
    Node<T>::Node(const Node<T>& node2)
{
    isEmptyNode = false;
    this->object = node2.object;
    this->key = node2.key;
    this->left = node2.left;
    this->right = node2.right;
    this->root = node2.root;
}

template < class T >
    int Node<T>::add(T inputObject, int inputKey)
{
    Node *pointer;
    
    if(isEmptyNode) {
        this->object = inputObject;
        this->key = inputKey;
        this->root = this;
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
                pointer->left->root = this->root;
                pointer->left->parent = pointer;
                break;
            }   
        } else {
            if(pointer->right) {
                pointer = pointer->right;
            } else {
                pointer->right = new Node(inputObject, inputKey);
                pointer->right->root = this->root;
                pointer->right->parent = pointer;
                break;
            }
        }
    }

    return 0;
}

template <class T> 
    Node<T>::~Node()
{
    if (this->left != NULL) {
        delete this->left;
    }
    if (this->right != NULL) {
        delete this->right;
    }
}

template < class T >
    ostream& operator<< (ostream& out, const Node<T>& inputNode)
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

template<class T>
    Node<T> Node<T>::operator= (Node<T>* obj2)
{
    this->object = obj2->object;
    this->key = obj2->key;

    if (obj2->left) {
        if (left) {
            left = obj2->left;
        }
    } else if (left) {
        delete left;
    }

    if (obj2->right) {
        if (right) {
            right = obj2->right;
        }
    } else if (left) {
        delete left;
    }
    
    return *this;
}

template<class T>
    int Node<T>::keyAreExists(int inputKey)
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

template<class T>
    int Node<T>::insertNodeInPlaceOfAnother(Node<T> insertedNode, Node<T>** node2)
{

    Node<T>* tempPointer;
    
    tempPointer = *node2;
    *node2 = NULL;
    *node2 = new Node(insertedNode->object, insertedNode->key);
    (*node2)->root = this->root;
    (*node2)->left = tempPointer;

    return 0;
}

template<class T>
    Node<T> Node<T>::operator+= (Node<T>* obj2)
{
    Node<T>* pointer;
    Node<T>* pointerAdress;

    pointer = root;
    while (true) {
        if (obj2->key < pointer->key) {
            if(pointer->left) {
                if(obj2->key > pointer->left->key) {
                    pointerAdress = pointer->left;
                    insertNodeInPlaceOfAnother(*obj2, &pointerAdress);
                    break;
                } else {
                    pointer = pointer->left;
                }
            } else {
                pointer->left = new Node(obj2->object, obj2->key);
                pointer->left->root = this->root;
                break;
            }   
        } else {
            if(pointer->right) {
                if(obj2->key > pointer->right->key) {
                    pointerAdress = pointer->right;
                    insertNodeInPlaceOfAnother(*obj2, &pointerAdress);
                    break;
                } else {
                    pointer = pointer->right;
                }
            } else {
                pointer->right = new Node(obj2->object, obj2->key);
                pointer->left->root = this->root;
                break;
            }
        }
    }

    if(obj2->left) {
        root += obj2->left;
    }
    if(obj2->right) {
        root += obj2->right;
    }

    return *this;
}


// }}} 

// {{{ Iterator

template<class T>
Node<T>::Iterator::Iterator()
{
    curr = NULL;
    prev = NULL;
}

template<class T>
Node<T>::Iterator::Iterator(const Node<T>::Iterator& otherIter)
{
    curr = otherIter.curr;    
    prev = otherIter.prev;
}

template<class T>
Node<T>::Iterator::Iterator(Node<T>* inPrev, Node<T>* inCurr)
{
    prev = inPrev;
    curr = inCurr;    
}

template<class T>
typename Node<T>::Iterator Node<T>::Iterator::operator = (const Node<T>::Iterator& inIter)
{
    curr = inIter.curr;
    prev = inIter.prev;
    return *this;
}

template<class T>
bool Node<T>::Iterator::operator <= (const Iterator& other)
{
    if(*this == other) {
        return true;
    } else if(!curr) {
        return false;
    } else if (!other.curr) {
        return true;
    }
     
    return curr->key <= other.curr->key;
} 

template<class T>
bool Node<T>::Iterator::operator >= (const Iterator& other)
{
    if(*this == other) {
        return true;
    } else if(!curr) {
        return false;
    } else if (!other.curr) {
        return true;
    }
     
    return curr->key >= other.curr->key; 
}

template<class T>
bool Node<T>::Iterator::operator != (const Iterator& other)
{
    if(*this == other) {
        return false;
    }
     
    return true;
} 

template<class T>
bool Node<T>::Iterator::operator == (const Iterator& other)
{
    if (this->curr == other.curr && this->prev == other.prev) {
        return true;
    }
    return false;
    //return (this->curr == other.curr && this->prev == other.prev) ;
} 

template<class T>
bool Node<T>::Iterator::operator < (const Iterator& other)
{
    if(!curr) {
        return false;
    } else if (!other.curr) {
        return true;
    }

    return curr->key < other.curr->key;
} 

template<class T>
bool Node<T>::Iterator::operator > (const Iterator& other)
{
    if(!curr) {
        return false;
    } else if (!other.curr) {
        return true;
    }

    return curr->key > other.curr->key;
} 

template<class T>
T Node<T>::Iterator::operator * ()
{
    if(!curr) {
        exit(1);
    }
    return curr->object;
}

template<class T>
typename Node<T>::Iterator Node<T>::Iterator::operator ++ ()
{
    if(!curr) {
        cout << "if(!curr)" << endl;
        return *this;
    }

    if(*this == curr->end()) {
        prev = curr; 
        curr = NULL;
        return *this;
    }
    
    prev = curr; 
    if(curr->right == NULL) { 
        while(curr->parent->key < curr->key) {
            curr = curr->parent;
        } 
        curr = curr->parent;
    } else {
        curr = curr->right;
        while(curr->left) {
            curr = curr->left;
        }
    }

    return *this;
}

template<class T>
typename Node<T>::Iterator Node<T>::Iterator::operator -- ()
{
    if(!prev) {
        //cout << "if(!curr)" << endl;
        return *this;
    }
    curr = prev; 

    if(*this == curr->end()) {
        //cout << "if(this == curr->end())" << endl;
        prev = NULL;
        return *this;
        cout << " -- " << endl;
    }
    
    if(prev->left == NULL) { 
        while(prev->parent->key >= prev->key) {
            prev = prev->parent;
        } 
        prev = prev->parent;
    } else {
        prev = prev->left;
        while(prev->right) {
            prev = prev->right;
        }
    }

    return *this;
}

template<class T>
typename Node<T>::Iterator Node<T>::Iterator::operator += (int incrementValue)
{
    int i;
    Node<T>::Iterator it = curr;

    for(i = 0; i < incrementValue; i++) {
        ++it;
    }
    this->curr = it.curr;

    return *this;
}

template<class T>
typename Node<T>::Iterator  Node<T>::Iterator::operator -= (int decrementValue)
{
    int i;
    Node<T>::Iterator it = curr;

    for(i = 0; i < decrementValue; i++) {
        --it;
    }
    this->curr = it.curr;

    return *this; 
}

// }}}

#endif
