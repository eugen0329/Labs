#ifndef ITERATOR_H
#define ITERATOR_H

template<class type1>
class NodeIterator {
public:
    explicit NodeIterator(type1); 
protected:
    type1* cur;
};

template<class type1>
NodeIterator::NodeIterator(type1 inCur)
{
    cur = inCur;
}





#endif
