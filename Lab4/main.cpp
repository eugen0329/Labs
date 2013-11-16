#include <cstdlib>
#include <iostream>
#include "products.hpp"
#include "tree.hpp"

using namespace std;

int main()
{
    Milk milk(100, 1, "ASd");
    Node<Milk, int> milkTree(milk, milk.getPrice());

    cout << milk << endl;
    return 0;
}
