#include <iostream>
#include "ThreeDShapes.hpp"
#include "TwoDShapes.hpp"

using namespace std;

int main()
{
    Treangle treangle(5, 2);
    Rectangle rectangle(3, 2);
    Circle circle(2);
    Cylinder cylinder(5, 2);
    Tetrahedron tetrahedron(3, 2);
    Parallelepiped parallelepiped(5, 2, 3);    
    Shape *basePointer;

    basePointer = &tetrahedron;
    cout << "Tetrahedron volume = ";
    cout << basePointer->getVolume() << endl;

    basePointer = &parallelepiped;
    cout << "parallelepiped volume = ";
    cout << basePointer->getVolume() << endl;

    basePointer = &cylinder;
    cout << "cylinder volume = ";
    cout << basePointer->getVolume() << endl;
    
    basePointer = &circle;
    cout << "Circle area = ";
    cout << basePointer->getArea() << endl;
    
    basePointer = &treangle;
    cout << "treangle area = ";
    cout << basePointer->getArea() << endl;
    
    basePointer = &rectangle;
    cout << "Rectangle area = ";
    cout << basePointer->getArea() << endl;

    return 0;
}

