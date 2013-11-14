#include <iostream>
#include "ThreeDShapes.hpp"
#include "TwoDShapes.hpp"

using namespace std;

int main()
{
    Treangle treangle(5, 2);                // arg1 = base, arg2 = heigth
    Rectangle rectangle(3, 2);              // arg1 = base, arg2 = heigth
    Circle circle(2);                       // arg1 = radius
    Cylinder cylinder(5, 2);                // arg1 = baseRadius, arg2 = heigth
    Tetrahedron tetrahedron(3, 2);          // arg1 = baseSide, arg2 = heigth
    Parallelepiped parallelepiped(5, 2, 3); // arg1 = length, arg2 = width, arg3
    Shape *basePointer[6];                     // = heigth

    basePointer[0] = new tetrahedron(3,2);
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

