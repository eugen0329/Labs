#include <cstdlib>
#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    SomeClass object;
    object.key = 2;
    object.number = 10;

    Node<SomeClass, int> root(object, object.key);

    cout << root.getKey();
    return 0;
}

