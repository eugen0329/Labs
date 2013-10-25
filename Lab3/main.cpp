#include <iostream>
#include "ThreeDShapes.hpp"
#include "TwoDShapes.hpp"

using namespace std;


void Shape::printShape()
{
    cout << "Shape";
}

int main()
{
    Treangle treangle(5);
    Rectangle rectangle(3);
    Circle circle;
    Cylinder cylinder;
    Tetrahedron tetrahedron;
    Parallelepiped parallelepiped(5);    

    cout << tetrahedron.getVolume() << '\n';
    cout << parallelepiped.getVolume() << '\n';
    cout << cylinder.getVolume() << '\n';
    cout << circle.getArea() << '\n';
    cout << treangle.getArea() << '\n';
    cout << rectangle.getArea() << '\n';  
    return 0;
}

